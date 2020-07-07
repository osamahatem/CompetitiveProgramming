/*
 * 11080 - Place the Guards.cpp
 *
 *  Created on: Sep 20, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int n, vis[200];
vector<vector<int>> adj;

int BFS(int src) {
	queue<int> Q;
	Q.push(src), vis[src] = 1;
	int cntRed = 0, cntBlue = 0;
	while (Q.size()) {
		int cur = Q.front();
		Q.pop();
		(vis[cur] == 1 ? cntRed : cntBlue)++;
		for (int i = 0; i < (int) adj[cur].size(); i++) {
			int to = adj[cur][i];
			if (!vis[to]) {
				Q.push(to), vis[to] = 3 - vis[cur];
			} else if (vis[to] == vis[cur]) {
				return -1;
			}
		}
	}
	return max(1, min(cntRed, cntBlue));
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int T;
	scanf("%d", &T);
	while (T--) {
		int m;
		scanf("%d%d", &n, &m);
		adj.assign(n, vector<int>());
		while (m--) {
			int u, v;
			scanf("%d%d", &u, &v);
			adj[u].push_back(v), adj[v].push_back(u);
		}
		memset(vis, 0, sizeof vis);
		int ans = 0;
		for (int i = 0; i < n; i++) {
			if (!vis[i]) {
				int temp = BFS(i);
				if (temp == -1) {
					ans = -1;
					break;
				} else {
					ans += temp;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
