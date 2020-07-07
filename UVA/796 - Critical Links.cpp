/*
 * 796 - Critical Links.cpp
 *
 *  Created on: Sep 27, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int n, id;
vector<vector<int>> adj;
vector<int> idx, low;
vector<bool> vis;
vector<pair<int, int>> ans;

void DFS(int cur, int p) {
	idx[cur] = low[cur] = ++id;
	vis[cur] = 1;
	for (int i = 0; i < (int) adj[cur].size(); i++) {
		int to = adj[cur][i];
		if (!vis[to]) {
			DFS(to, cur);
			low[cur] = min(low[cur], low[to]);
			if (low[to] > idx[cur])
				ans.push_back( { min(cur, to), max(cur, to) });
		} else if (to != p) {
			low[cur] = min(low[cur], idx[to]);
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	while (scanf("%d", &n) != EOF) {
		adj.assign(n, vector<int>());
		for (int i = 0; i < n; i++) {
			int u, m, v;
			scanf("%d (%d)", &u, &m);
			while (m--) {
				scanf("%d", &v);
				adj[u].push_back(v);
			}
		}
		ans.clear(), id = 0;
		idx.assign(n, 0), low.assign(n, 0), vis.assign(n, 0);
		for (int i = 0; i < n; i++)
			if (!vis[i])
				DFS(i, -1);
		sort(ans.begin(), ans.end());
		printf("%d critical links\n", (int) ans.size());
		for (int i = 0; i < (int) ans.size(); i++)
			printf("%d - %d\n", ans[i].first, ans[i].second);
		printf("\n");
	}
	return 0;
}
