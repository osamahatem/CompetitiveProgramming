/*
 * 191C. Fools and Roads.cpp
 *
 *  Created on: Sep 16, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;
const int LOGN = 17;

int n, q, par[LOGN][MAXN], depth[MAXN], sum[MAXN], ans[MAXN];
vector<pair<int, int>> adj[MAXN];

void DFS(int idx, int p, int d, bool solve) {
	par[0][idx] = p, depth[idx] = d;
	for (int i = 0; i < (int) adj[idx].size(); i++) {
		int to = adj[idx][i].first;
		if (to != p) {
			DFS(to, idx, d + 1, solve);
			sum[idx] += sum[to];
		}
	}
	if (solve) {
		for (int i = 0; i < (int) adj[idx].size(); i++) {
			int to = adj[idx][i].first, edgeID = adj[idx][i].second;
			if (to != p)
				ans[edgeID] = sum[to];
		}
	}
}

void buildPar() {
	for (int i = 1; i < LOGN; i++)
		for (int j = 1; j <= n; j++)
			par[i][j] = par[i - 1][par[i - 1][j]];
}

int LCA(int u, int v) {
	if (depth[u] > depth[v])
		swap(u, v);
	for (int i = LOGN - 1; i >= 0; i--)
		if (depth[par[i][v]] >= depth[u])
			v = par[i][v];
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

	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		adj[u].push_back( { v, i });
		adj[v].push_back( { u, i });
	}
	DFS(1, 0, 1, 0);
	buildPar();
	scanf("%d", &q);
	while (q--) {
		int u, v;
		scanf("%d%d", &u, &v);
		int lca = LCA(u, v);
		sum[u]++, sum[v]++, sum[lca] -= 2;
	}
	DFS(1, 0, 1, 1);
	for (int i = 1; i < n; i++) {
		if (i > 1)
			printf(" ");
		printf("%d", ans[i]);
	}
	printf("\n");
	return 0;
}
