/*
 * 4449 - Fare and Balanced.cpp
 *
 *  Created on: Feb 2, 2018
 *      Author: Osama Hatem
 */
 
/*
The final cost is always the longest path from node 1 to node N. Suppose there
exists a solution for a larger cost, since the toll is added to only 1 edge per
route, we can subtract the difference from all such edges and end up with a
solution with a cost equal to the longest path.
We pre-compute the shortest and longest path from each node to node N, and then
we perform a DFS from node 1. For each node, the DFS is called with the required
cost for all routes starting at this node, let's call this amount need, so node
1 is called with need = longest path.
At each node, for every child it has, if the child's longest and shortest paths
are equal then we apply the extra toll on the edge going from the current node
to that child. Otherwise, we cannot add the toll here and must propagate the
need to that child, after subtracting the edge's cost, because the paths' costs
will diverge later down the DAG and the toll is limited to 1 edge per route.
If a node is reached with multiple needs, then there is no solution satisfying
the problem's constraints.
*/

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 5e4 + 5;

int n, m;
int head[MAXN], nxt[MAXN], to[MAXN], cost[MAXN], last;
int sp[MAXN], lp[MAXN], need[MAXN], ans[MAXN];
bool vis[MAXN];

void addEdge(int u, int v, int c) {
	to[last] = v;
	cost[last] = c;
	nxt[last] = head[u];
	head[u] = last++;
}

void pre(int src) {
	sp[src] = src != n ? 1e9 : 0, lp[src] = 0, vis[src] = true;
	for (int i = head[src]; ~i; i = nxt[i]) {
		if (!vis[to[i]])
			pre(to[i]);
		sp[src] = min(sp[src], sp[to[i]] + cost[i]);
		lp[src] = max(lp[src], lp[to[i]] + cost[i]);
	}
}

bool solve(int src, int _need) {
	need[src] = _need, vis[src] = true;
	for (int i = head[src]; ~i; i = nxt[i]) {
		if (sp[to[i]] == lp[to[i]])
			ans[i] = _need - lp[to[i]] - cost[i];
		else if ((!vis[to[i]] && !solve(to[i], _need - cost[i]))
				|| (vis[to[i]] && _need - cost[i] != need[to[i]]))
			return false;
	}
	return true;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int T = 0, u, v, c;
	while (cin >> n >> m, n) {
		memset(head, -1, sizeof head), last = 0;
		while (m--) {
			cin >> u >> v >> c;
			addEdge(u, v, c);
		}

		memset(vis, 0, sizeof vis);
		pre(1);

		cout << "Case " << ++T << ": ";
		memset(vis, 0, sizeof vis);
		memset(ans, 0, sizeof ans);
		if (solve(1, lp[1])) {
			int cnt = 0;
			for (int i = 0; i < last; i++)
				if (ans[i])
					cnt++;
			cout << cnt << " " << lp[1] << endl;
			for (int i = 0; i < last; i++)
				if (ans[i])
					cout << i + 1 << " " << ans[i] << endl;
		} else
			cout << "No solution" << endl;
	}
	return 0;
}
