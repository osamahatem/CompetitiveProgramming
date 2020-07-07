/*
 * 362E. Petya and Pipes.cpp
 *
 *  Created on: Jul 18, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 50;
const int MAXE = 10000;

int n, k, dist[50], par[50], pare[50], capp[50], inQ[50];
int head[MAXN], nxt[MAXE], to[MAXE], cost[MAXE], cap[MAXE], last;

void addEdge(int f, int t, int co, int ca) {
	to[last] = t;
	cap[last] = ca;
	cost[last] = co;
	nxt[last] = head[f];
	head[f] = last++;
}

void addAugEdge(int f, int t, int co, int ca) {
	addEdge(f, t, co, ca);
	addEdge(t, f, -co, 0);
}

void bellman() {
	memset(dist, 127, sizeof dist);
	memset(capp, 127, sizeof capp);
	memset(par, -1, sizeof par);
	memset(pare, -1, sizeof pare);
	memset(inQ, 0, sizeof inQ);
	queue<int> Q;
	dist[0] = 0, Q.push(0), inQ[0] = 1;
	while (Q.size()) {
		int cur = Q.front();
		Q.pop(), inQ[cur] = 0;
		for (int i = head[cur]; i != -1; i = nxt[i]) {
			if (cap[i] && dist[cur] + cost[i] < dist[to[i]]) {
				dist[to[i]] = dist[cur] + cost[i];
				capp[to[i]] = min(capp[cur], (i % 4 > 1 ? 1 : cap[i]));
				par[to[i]] = cur, pare[to[i]] = i;
				if (!inQ[to[i]])
					Q.push(to[i]), inQ[to[i]] = 1;
			}
		}
	}
}

int solve() {
	int ans = 0;
	while (bellman(), par[n - 1] != -1 && dist[n - 1] <= k) {
		k -= dist[n - 1], ans += capp[n - 1];
		int x = n - 1;
		while (x) {
			int e = pare[x];
			cap[e] -= capp[n - 1], cap[e ^ 1] += capp[n - 1];
			x = par[x];
		}
	}
	return ans;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	memset(head, -1, sizeof head);
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			int x;
			scanf("%d", &x);
			if (x) {
				addAugEdge(i, j, 0, x);
				addAugEdge(i, j, 1, 1 << 30);
			}
		}
	printf("%d\n", solve());
	return 0;
}
