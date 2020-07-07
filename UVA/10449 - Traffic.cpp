/*
 * 10449 - Traffic.cpp
 *
 *  Created on: Sep 14, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int n, m, busy[205], dist[205];
bool valid[205], adj[205][205];

void bellman() {
	dist[1] = 0;
	for (int it = 1; it < n; it++) {
		for (int s = 1; s <= n; s++) {
			for (int e = 1; e <= n; e++) {
				if (!adj[s][e])
					continue;
				int cost = busy[e] - busy[s];
				cost *= cost * cost;
				if (dist[s] + cost < dist[e])
					dist[e] = dist[s] + cost;
			}
		}
	}
	for (int it = 1; it < n; it++) {
		for (int s = 1; s <= n; s++) {
			for (int e = 1; e <= n; e++) {
				if (!adj[s][e])
					continue;
				int cost = busy[e] - busy[s];
				cost *= cost * cost;
				if (dist[s] + cost < dist[e])
					dist[e] = dist[s] + cost, valid[e] = valid[s] = 0;
			}
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int T = 0;
	while (scanf("%d", &n)) {
		memset(adj, 0, sizeof adj);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &busy[i]);
			valid[i] = 1, dist[i] = 1 << 28;
		}
		scanf("%d", &m);
		while (m--) {
			int u, v;
			scanf("%d%d", &u, &v);
			adj[u][v] = 1;
		}
		bellman();
		int q;
		scanf("%d", &q);
		printf("Set #%d\n", ++T);
		while (q--) {
			int x;
			scanf("%d", &x);
			if (!valid[x] || dist[x] < 3 || dist[x] >= 1 << 27)
				printf("?\n");
			else
				printf("%d\n", dist[x]);
		}
	}
	return 0;
}
