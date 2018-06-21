/*
 * 101102K. Topological Sort.cpp
 *
 *  Created on: Jun 20, 2018
 *      Author: Osama Hatem
 */

/*
 * This would've been a simple problem if it wasn't for the fact that we're
 * given the missing edges instead of the existing ones. We can use a set to
 * hold all unvisited nodes, and use it, along with binary search over the input
 * adjacency list, to perform a DFS.
 * Time complexity: O(N * log(N))
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;

int n, m;
vector<int> adj[MAXN], ans;
set<int> vis;

void solve(int idx) {
	vis.erase(idx);

	int x = idx;
	while (1) {
		auto nxt = vis.upper_bound(x);
		if (nxt == vis.end())
			break;

		if (binary_search(adj[idx].begin(), adj[idx].end(), *nxt)) {
			x = *nxt;
			continue;
		}

		solve(*nxt);
	}
	ans.push_back(idx);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;
	while (T--) {
		cin >> n >> m;

		ans.clear(), vis.clear();
		for (int i = 1; i <= n; i++)
			adj[i].clear(), vis.insert(i);

		while (m--) {
			int a, b;
			cin >> a >> b;
			adj[a].push_back(b);
		}

		for (int i = 1; i <= n; i++)
			sort(adj[i].begin(), adj[i].end());

		for (int i = 1; i <= n; i++)
			if (vis.count(i))
				solve(i);

		reverse(ans.begin(), ans.end());
		for (int i = 0; i < (int) ans.size(); i++) {
			if (i)
				cout << " ";
			cout << ans[i];
		}
		cout << endl;
	}
	return 0;
}
