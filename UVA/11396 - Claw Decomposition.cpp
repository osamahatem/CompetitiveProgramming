/*
 * 11396 - Claw Decomposition.cpp
 *
 *  Created on: Sep 20, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int n, vis[300];
vector<vector<int>> adj;

bool BFS(int src) {
	queue<int> Q;
	Q.push(src), vis[src] = 1;
	while (Q.size()) {
		int cur = Q.front();
		Q.pop();
		for (int i = 0; i < (int) adj[cur].size(); i++) {
			int to = adj[cur][i];
			if (!vis[to]) {
				Q.push(to), vis[to] = 3 - vis[cur];
			} else if (vis[to] == vis[cur]) {
				return false;
			}
		}
	}
	return true;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	while (scanf("%d", &n), n) {
		adj.assign(n, vector<int>());
		memset(vis, 0, sizeof vis);
		int u, v;
		while (scanf("%d%d", &u, &v), u || v) {
			u--, v--;
			adj[u].push_back(v), adj[v].push_back(u);
		}
		bool ans = true;
		for (int i = 0; i < n; i++) {
			if (!vis[i]) {
				ans &= BFS(i);
			}
		}
		printf("%s\n", ans ? "YES" : "NO");
	}
	return 0;
}
