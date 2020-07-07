/*
 * 10557 - XYZZY.cpp
 *
 *  Created on: Sep 15, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int n, energy[101];
vector<int> adj[101];

bool bellman() {
	vector<int> dist(n + 1, 1 << 20);
	dist[1] = -100;
	for (int cnt = 1; cnt < n; cnt++) {
		for (int cur = 1; cur <= n; cur++) {
			for (int i = 0; i < (int) adj[cur].size(); i++) {
				int to = adj[cur][i];
				int cost = dist[cur] + energy[to];
				if (cost < dist[to] && cost < 0)
					dist[to] = cost;
			}
		}
	}
	for (int cnt = 1; cnt < n; cnt++) {
		for (int cur = 1; cur <= n; cur++) {
			for (int i = 0; i < (int) adj[cur].size(); i++) {
				int to = adj[cur][i];
				int cost = dist[cur] + energy[to];
				if (cost < dist[to] && cost < 0)
					dist[to] = -(1 << 20);
			}
		}
	}
	return dist[n] < 0;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	while (scanf("%d", &n), n != -1) {
		for (int i = 1; i <= n; i++) {
			int nr;
			scanf("%d%d", &energy[i], &nr);
			energy[i] = -energy[i];
			adj[i].resize(nr);
			for (int j = 0; j < nr; j++)
				scanf("%d", &adj[i][j]);
		}
		printf("%s\n", bellman() ? "winnable" : "hopeless");
	}
	return 0;
}
