/*
 * 924 - Spreading The News.cpp
 *
 *  Created on: Sep 13, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int n;
vector<int> adj[2500];
bool vis[2500];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int cnt, x;
		scanf("%d", &cnt);
		while (cnt--) {
			scanf("%d", &x);
			adj[i].push_back(x);
		}
	}
	int T;
	scanf("%d", &T);
	while (T--) {
		int src, steps = 0, m = -1, d = -1;
		scanf("%d", &src);
		memset(vis, 0, sizeof vis);
		queue<int> Q;
		Q.push(src), vis[src] = 1;
		while (Q.size()) {
			int sz = Q.size();
			if (steps && sz > m)
				m = sz, d = steps;
			while (sz--) {
				int cur = Q.front();
				Q.pop();
				for (int i = 0; i < (int) adj[cur].size(); i++) {
					int to = adj[cur][i];
					if (!vis[to])
						Q.push(to), vis[to] = 1;
				}
			}
			steps++;
		}
		if (m == -1)
			printf("0\n");
		else
			printf("%d %d\n", m, d);
	}
	return 0;
}
