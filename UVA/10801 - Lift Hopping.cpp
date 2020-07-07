/*
 * 10801 - Lift Hopping.cpp
 *
 *  Created on: Sep 14, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int n, k, sp[5];
bool adj[5][100];

int dijkstra() {
	vector<int> dist(100, INT_MAX);
	dist[0] = 0;
	set<pair<int, int>> active;
	active.insert( { 0, 0 });
	while (active.size()) {
		int cur = active.begin()->second;
		active.erase(active.begin());
		if (cur == k)
			return dist[cur];
		for (int e = 0; e < 5; e++) {
			if (!adj[e][cur])
				continue;
			for (int i = 0; i < 100; i++) {
				if (!adj[e][i])
					continue;
				int cost = dist[cur] + 60 * (cur > 0) + sp[e] * abs(cur - i);
				if (cost < dist[i]) {
					active.erase( { dist[i], i });
					dist[i] = cost;
					active.insert( { dist[i], i });
				}
			}
		}
	}
	return -1;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	while (scanf("%d%d", &n, &k) != EOF) {
		memset(adj, 0, sizeof adj);
		for (int i = 0; i < n; i++)
			scanf("%d", &sp[i]);
		int idx = 0;
		while (idx < n) {
			int x;
			char c;
			int r = scanf("%d%c", &x, &c);
			adj[idx][x] = 1;
			if (c == 10 || r < 2)
				idx++;
		}
		int ans = dijkstra();
		if (ans == -1)
			printf("IMPOSSIBLE\n");
		else
			printf("%d\n", ans);
	}
	return 0;
}
