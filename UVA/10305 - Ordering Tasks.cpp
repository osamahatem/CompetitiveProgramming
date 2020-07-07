/*
 * 10305 - Ordering Tasks.cpp
 *
 *  Created on: Sep 16, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int n, m, deg[101];
vector<int> adj[101];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	while (scanf("%d%d", &n, &m), n || m) {
		for (int i = 1; i <= m; i++)
			adj[i].clear(), deg[i] = 0;
		while (m--) {
			int u, v;
			scanf("%d%d", &u, &v);
			deg[v]++;
			adj[u].push_back(v);
		}
		queue<int> Q;
		for (int i = 1; i <= n; i++)
			if (!deg[i])
				Q.push(i);
		for (int i = 0; i < n; i++) {
			if (i)
				printf(" ");
			int cur = Q.front();
			Q.pop();
			for (int j = 0; j < (int) adj[cur].size(); j++)
				if (--deg[adj[cur][j]] == 0)
					Q.push(adj[cur][j]);
			printf("%d", cur);
		}
		printf("\n");
	}
	return 0;
}
