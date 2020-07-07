/*
 * C. Connections.cpp
 *
 *  Created on: Sep 15, 2018
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;

int n, m, cnt;
vector<pair<int, int>> adj[MAXN], rev_adj[MAXN];
vector<pair<int, int>> edges;
bool vis[MAXN], vis_edge[MAXN];

void dfs(int idx, vector<pair<int, int>> adj[]) {
	vis[idx] = true;

	for (auto p : adj[idx]) {
		if (!vis[p.first]) {
			if (!vis_edge[p.second])
				cnt++;
			vis_edge[p.second] = true;
			dfs(p.first, adj);
		}
	}
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

		cnt = 0;
		memset(vis_edge, 0, sizeof vis_edge);
		for (int i = 1; i <= n; i++)
			adj[i].clear(), rev_adj[i].clear();
		edges.clear();

		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			edges.push_back(make_pair(a, b));
			adj[a].push_back(make_pair(b, i));
			rev_adj[b].push_back(make_pair(a, i));
		}

		memset(vis, 0, sizeof vis);
		dfs(1, adj);

		memset(vis, 0, sizeof vis);
		dfs(1, rev_adj);

		for (int i = 0; i < m; i++)
			if (!vis_edge[i]) {
				if (cnt < n * 2)
					cnt++;
				else
					cout << edges[i].first << " " << edges[i].second << endl;
			}
	}
	return 0;
}
