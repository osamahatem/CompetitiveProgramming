/*
 * I. OCPC2014.cpp
 *
 *  Created on: Sep 10, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;
const int MAXE = 2 * MAXN;
const int LOGN = 17;

int head[MAXN], to[MAXE], nxt[MAXE], cost[MAXE], last;
int N, Q, par[LOGN][MAXN], dep[MAXN], sum[MAXN];

void addEdge(int f, int t, int c) {
	to[last] = t;
	cost[last] = c;
	nxt[last] = head[f];
	head[f] = last++;
}

void addBiEdge(int f, int t, int c) {
	addEdge(f, t, c);
	addEdge(t, f, c);
}

void dfs(int n, int pr) {
	for (int i = head[n]; i != -1; i = nxt[i])
		if (to[i] != pr) {
			sum[to[i]] = sum[n] + cost[i], dep[to[i]] = dep[n] + 1, par[0][to[i]] =
					n;
			dfs(to[i], n);
		}
}

void fillPar() {
	for (int i = 1; i < LOGN; i++)
		for (int j = 1; j <= N; j++)
			if (par[i - 1][j] != -1)
				par[i][j] = par[i - 1][par[i - 1][j]];
}

int getParAt(int n, int _dep) {
	for (int i = LOGN - 1; i >= 0; i--)
		if (dep[n] - (1 << i) >= _dep)
			n = par[i][n];
	return n;
}

int LCA(int u, int v) {
	if (dep[u] > dep[v])
		swap(u, v);
	v = getParAt(v, dep[u]);
	if (u == v)
		return u;
	for (int i = LOGN - 1; i >= 0; i--)
		if (par[i][u] != par[i][v])
			u = par[i][u], v = par[i][v];
	return par[0][u];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	freopen("ocpc2014.in", "r", stdin);
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		memset(head, -1, sizeof head), last = 0;
		memset(par, -1, sizeof par);
		printf("Case %d:\n", t);
		int a, b, c;
		scanf("%d", &N);
		for (int i = 1; i < N; i++) {
			scanf("%d%d%d", &a, &b, &c);
			addBiEdge(a, b, c);
		}
		dfs(1, 0);
		fillPar();
		scanf("%d", &Q);
		while (Q--) {
			scanf("%d%d", &a, &b);
			c = LCA(a, b);
			printf("%d\n", sum[a] + sum[b] - 2 * sum[c]);
		}
	}
	return 0;
}
