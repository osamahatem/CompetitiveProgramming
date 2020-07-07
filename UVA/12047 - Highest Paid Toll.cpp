/*
 * 12047 - Highest Paid Toll.cpp
 *
 *  Created on: Sep 14, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e4 + 5;
const int MAXE = 1e5 + 5;

int N, M, src, tar, p;
int head[MAXN], nxt[MAXE], to[MAXE], cost[MAXE], last;
int dist[MAXN][2];

void addEdge(int f, int t, int c) {
	to[last] = t;
	cost[last] = c;
	nxt[last] = head[f];
	head[f] = last++;
}

bool dijkstra(int val) {
	memset(dist, 127, sizeof dist);
	dist[src][0] = 0;
	set<pair<int, pair<int, bool>>> active;
	active.insert( { 0, { src, 0 } });
	while (active.size()) {
		int cur = active.begin()->second.first;
		int used = active.begin()->second.second;
		active.erase(active.begin());
		if (cur == tar && used)
			return true;
		for (int i = head[cur]; i != -1; i = nxt[i]) {
			int newUsed = used || (cost[i] >= val);
			int newCost = dist[cur][used] + cost[i];
			if (newCost <= p && newCost < dist[to[i]][newUsed]) {
				active.erase( { dist[to[i]][newUsed], { to[i], newUsed } });
				dist[to[i]][newUsed] = newCost;
				active.insert( { dist[to[i]][newUsed], { to[i], newUsed } });
			}
		}
	}
	return false;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int T;
	scanf("%d", &T);
	while (T--) {
		memset(head, -1, sizeof head), last = 0;
		scanf("%d%d%d%d%d", &N, &M, &src, &tar, &p);
		while (M--) {
			int u, v, c;
			scanf("%d%d%d", &u, &v, &c);
			addEdge(u, v, c);
		}
		int s = -1, e = MAXE;
		while (s < e) {
			int mid = (s + e + 1) / 2;
			if (dijkstra(mid))
				s = mid;
			else
				e = mid - 1;
		}
		printf("%d\n", s);
	}
	return 0;
}
