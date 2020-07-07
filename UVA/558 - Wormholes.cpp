/*
 * 558 - Wormholes.cpp
 *
 *  Created on: Sep 14, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1005;
const int MAXE = 2005;

int n, m;
int head[MAXN], to[MAXE], nxt[MAXE], cost[MAXE], last;

void addEdge(int f, int t, int c) {
	to[last] = t;
	cost[last] = c;
	nxt[last] = head[f];
	head[f] = last++;
}

bool bellman() {
	vector<int> dist(n, INT_MAX);
	vector<bool> inQ(n, 0);
	dist[0] = 0;
	queue<int> Q;
	Q.push(0), inQ[0] = 1;
	for (int cnt = 0; cnt + 1 < n && Q.size(); cnt++) {
		int cur = Q.front();
		Q.pop(), inQ[cur] = 0;
		for (int i = head[cur]; i != -1; i = nxt[i]) {
			if (dist[cur] + cost[i] < dist[to[i]]) {
				dist[to[i]] = dist[cur] + cost[i];
				if (!inQ[to[i]])
					Q.push(to[i]), inQ[to[i]] = 1;
			}
		}
	}
	for (int cur = 0; cur < n; cur++)
		for (int i = head[cur]; i != -1; i = nxt[i])
			if (dist[cur] + cost[i] < dist[to[i]])
				return true;
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
		scanf("%d%d", &n, &m);
		while (m--) {
			int u, v, c;
			scanf("%d%d%d", &u, &v, &c);
			addEdge(u, v, c);
		}
		printf("%s\n", bellman() ? "possible" : "not possible");
	}
	return 0;
}
