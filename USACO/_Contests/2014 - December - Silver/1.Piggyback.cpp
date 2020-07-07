/*
 * 1.Piggyback.cpp
 *
 *  Created on: Dec 15, 2014
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 40005;
const int INF = 1 << 28;

int b, e, p, n, m;
int dist1[MAXN], dist2[MAXN], distn[MAXN];
bool vis[MAXN];
vector<int> adj[MAXN];

void BFS(int src, int dist[]) {
	memset(vis, 0, sizeof vis);
	queue<int> Q;
	Q.push(src);
	int steps = -1;
	while (Q.size()) {
		int sz = Q.size();
		steps++;
		while (sz--) {
			int c = Q.front();
			Q.pop();
			if (vis[c])
				continue;
			dist[c] = steps;
			vis[c] = 1;
			for (int i = 0; i < (int) adj[c].size(); i++)
				Q.push(adj[c][i]);
		}
	}
}

int main() {
//#ifndef ONLINE_JUDGE
	freopen("piggyback.in", "r", stdin);
	freopen("piggyback.out", "w", stdout);
//#endif

	cin >> b >> e >> p >> n >> m;
	fill(dist1, dist1 + n + 1, INF);
	fill(dist2, dist2 + n + 1, INF);
	fill(distn, distn + n + 1, INF);
	int u, v;
	while (m--) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	BFS(1, dist1);
	BFS(2, dist2);
	BFS(n, distn);
	long long ans = (long long) (dist1[n] * b) + dist2[n] * e;
	for (int i = 1; i <= n; i++) {
		if (dist1[i] == INF || dist2[i] == INF || distn[i] == INF)
			continue;
		long long temp = dist1[i] * b;
		temp += dist2[i] * e + distn[i] * p;
		ans = min(temp, ans);
	}
	cout << ans << endl;
	return 0;
}
