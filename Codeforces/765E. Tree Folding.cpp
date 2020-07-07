/*
 * 765E. Tree Folding.cpp
 *
 *  Created on: Feb 15, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 2e5 + 5;

vector<int> adj[MAXN];
int n, deg[MAXN];
set<int> dist[MAXN];

void NO() {
	printf("-1\n");
	exit(0);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		adj[u].push_back(v), adj[v].push_back(u);
		deg[u]++, deg[v]++;
	}
	queue<int> Q;
	for (int i = 1; i <= n; i++)
		if (deg[i] == 1)
			Q.push(i), dist[i].insert(0);
	int ans = 0;
	while (Q.size()) {
		int x = Q.front();
		Q.pop();
		if (!deg[x] && dist[x].size() < 3)
			for (auto it = dist[x].begin(); it != dist[x].end(); it++)
				ans += *it;
		else if (dist[x].size() > 1)
			NO();
		for (int y : adj[x]) {
			if (!deg[y])
				continue;
			deg[x]--, deg[y]--;
			dist[y].insert(*dist[x].begin() + 1);
			if (deg[y] == 1)
				Q.push(y);
		}
	}
	while (ans % 2 == 0)
		ans /= 2;
	printf("%d\n", ans);
	return 0;
}
