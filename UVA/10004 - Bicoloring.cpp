/*
 * 10004 - Bicoloring.cpp
 *
 *  Created on: Sep 20, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int n;
vector<vector<int>> adj;

bool check() {
	vector<int> vis(n, 0);
	queue<int> Q;
	Q.push(0), vis[0] = 1;
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
		int m;
		scanf("%d", &m);
		while (m--) {
			int u, v;
			scanf("%d%d", &u, &v);
			adj[u].push_back(v), adj[v].push_back(u);
		}
		printf("%sBICOLORABLE.\n", check() ? "" : "NOT ");
	}
	return 0;
}
