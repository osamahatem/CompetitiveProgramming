/*
 * SHPATH.cpp
 *
 *  Created on: Sep 14, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

struct edge {
	int to, cost;
};

vector<string> cities;
vector<edge> adj[10005];
char temp[15], tempb[15];
int n;

int dijkstra(int src, int tar) {
	vector<int> dist(n + 1, INT_MAX);
	dist[src] = 0;
	set<pair<int, int>> active;
	active.insert( { 0, src });
	while (active.size()) {
		int cur = active.begin()->second;
		active.erase(active.begin());
		if (cur == tar)
			return dist[tar];
		for (auto ed : adj[cur]) {
			if (dist[cur] + ed.cost < dist[ed.to]) {
				active.erase( { dist[ed.to], ed.to });
				dist[ed.to] = dist[cur] + ed.cost;
				active.insert( { dist[ed.to], ed.to });
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

	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		cities.resize(n + 1);
		for (int i = 1; i <= n; i++) {
			scanf("%s", temp);
			cities[i] = temp;
			int p;
			scanf("%d", &p);
			adj[i].resize(p);
			for (int j = 0; j < p; j++)
				scanf("%d%d", &adj[i][j].to, &adj[i][j].cost);
		}
		int m;
		scanf("%d", &m);
		while (m--) {
			scanf("%s%s", temp, tempb);
			int src = find(cities.begin() + 1, cities.end(), temp)
					- cities.begin();
			int tar = find(cities.begin() + 1, cities.end(), tempb)
					- cities.begin();
			printf("%d\n", dijkstra(src, tar));
		}
	}
	return 0;
}
