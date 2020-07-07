/*
 * 12821 - Double Shortest Paths.cpp
 *
 *  Created on: Nov 24, 2014
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 505;
const int MAXE = 8005;
const int SRC = MAXN - 1;
const int SNK = MAXN - 2;
const int INF = 1 << 28;

int n, m, tc = 0;
int head[MAXN], to[MAXE], nxt[MAXE], cost[MAXE], cap[MAXE], last;
int dist[MAXN], par[MAXN], edge[MAXN];
bool inQ[MAXN];

void init() {
	memset(head, -1, sizeof head);
	last = 0;
}

void addEdge(int f, int t, int co, int ca) {
	nxt[last] = head[f];
	to[last] = t;
	cost[last] = co;
	cap[last] = ca;
	head[f] = last++;
}

void addAugEdge(int f, int t, int co, int ca) {
	addEdge(f, t, co, ca);
	addEdge(t, f, -co, 0);
}

int bellman() {
	fill(dist, dist + MAXN, INF);
	memset(inQ, 0, sizeof inQ);
	dist[SRC] = 0;
	queue<int> Q;
	Q.push(SRC), inQ[SRC] = 1;
	for (int it = 0; it <= n; it++) {
		int sz = Q.size();
		while (sz--) {
			int cur = Q.front();
			inQ[cur] = 0;
			Q.pop();
			for (int i = head[cur]; i != -1; i = nxt[i])
				if (cap[i] && dist[cur] + cost[i] < dist[to[i]]) {
					dist[to[i]] = dist[cur] + cost[i];
					par[to[i]] = cur, edge[to[i]] = i;
					if (!inQ[to[i]])
						Q.push(to[i]), inQ[to[i]] = 1;
				}
		}
		if (Q.empty())
			break;
	}
	return dist[SNK];
}

int minCostMaxFlow() {
	int ans = 0;
	while (1) {
		int temp = bellman();
		if (temp == INF)
			break;
		ans += temp;
		for (int i = SNK; i != SRC; i = par[i]) {
			int e = edge[i];
			cap[e]--;
			cap[e ^ 1]++;
		}
	}
	return ans;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	while (cin >> n >> m) {
		init();
		int u, v, d, a;
		while (m--) {
			cin >> u >> v >> d >> a;
			addAugEdge(u, v, d, 1);
			addAugEdge(u, v, d + a, 1);
		}
		addAugEdge(SRC, 1, 0, 2);
		addAugEdge(n, SNK, 0, 2);
		cout << "Case " << ++tc << ": " << minCostMaxFlow() << endl;
	}
	return 0;
}
