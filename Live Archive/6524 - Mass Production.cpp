/*
 * 6524 - Mass Production.cpp
 *
 *  Created on: Aug 2, 2014
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 10;
const int MAXV = 3 * MAXN + 2;
const int MAXE = MAXV * MAXV;
const int src = MAXV - 1;
const int snk = MAXV - 2;

int head[MAXV], cap[MAXE], cost[MAXE], to[MAXE], from[MAXE], next[MAXE], last;
int par[MAXV], inQ[MAXV], dist[MAXV], id = 2;
int m, n, a, b;

void init() {
	last = 0;
	memset(head, -1, sizeof head);
}

void addEdge(int f, int t, int ca, int co) {
	next[last] = head[f];
	to[last] = t;
	from[last] = f;
	cap[last] = ca;
	cost[last] = co;
	head[f] = last++;
}

void addAugEdge(int f, int t, int ca, int co) {
	addEdge(f, t, ca, co);
	addEdge(t, f, 0, -co);
}

bool bellman() {
	++id;
	queue<int> Q;
	for (int i = 0; i < MAXV; i++)
		dist[i] = 1e8;
	Q.push(src);
	inQ[src] = id;
	dist[src] = 0;
	for (int i = 0; i < MAXV; i++) {
		int s = Q.size();
		while (s--) {
			int cur = Q.front();
			Q.pop();
			inQ[cur] = 0;
			for (int j = head[cur]; j != -1; j = next[j]) {
				int t = to[j];
				if (cap[j] > 0 && dist[cur] + cost[j] < dist[t]) {
					dist[t] = dist[cur] + cost[j];
					par[t] = j;
					if (inQ[t] != id)
						Q.push(t), inQ[t] = id;
				}
			}
		}
		if (Q.empty() && dist[snk] < 1e8)
			return true;
	}
	return false;
}

int minCostMaxFlow() {
	int ans = 0, temp;
	while (bellman()) {
		temp = dist[snk];
		int maxCap = 100;
		for (int i = snk; i != src; i = from[par[i]])
			maxCap = min(maxCap, cap[par[i]]);
		for (int i = snk; i != src; i = from[par[i]]) {
			cap[par[i]] -= maxCap;
			cap[par[i] ^ 1] += maxCap;
		}
		ans += temp * maxCap;
	}
	return ans;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif

	int t, x;
	scanf("%d", &t);
	while (t--) {
		init();
		scanf("%d%d%d%d", &m, &n, &a, &b);
		for (int i = 0; i < n; i++) {
			scanf("%d", &x);
			addAugEdge(src, i, x, 0);
		}
		for (int i = 0; i < n; i++) {
			scanf("%d", &x);
			addAugEdge(m + n + i, snk, x, 0);
		}
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%d", &x);
				addAugEdge(j, n + i, 100, a * x);
				addAugEdge(n + i, m + n + j, 100, b * x);
			}
		}
		printf("%d\n", minCostMaxFlow());
	}
	return 0;
}
