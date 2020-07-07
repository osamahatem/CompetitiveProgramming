/*
 * I. Tourists.cpp
 *
 *  Created on: Aug 29, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 2e5 + 5;
const int LOGN = 18;

vector<int> adj[MAXN];
int N, dep[MAXN], par[LOGN][MAXN];

void dfs(int n, int d, int p) {
	dep[n] = d, par[0][n] = p;
	for (int i = 0; i < (int) adj[n].size(); i++)
		if (adj[n][i] != p)
			dfs(adj[n][i], d + 1, n);
}

void buildPar() {
	for (int i = 1; i < LOGN; i++)
		for (int j = 1; j <= N; j++)
			if (par[i - 1][j] != -1)
				par[i][j] = par[i - 1][par[i - 1][j]];
}

int lca(int u, int v) {
	if (dep[u] > dep[v])
		swap(u, v);
	for (int i = LOGN - 1; i >= 0; i--)
		if (dep[v] - (1 << i) >= dep[u])
			v = par[i][v];
	if (u == v)
		return u;
	for (int i = LOGN - 1; i >= 0; i--)
		if (par[i][u] != par[i][v])
			u = par[i][u], v = par[i][v];
	return par[0][u];
}

int getPath(int u, int v) {
	int l = lca(u, v);
	return dep[u] + dep[v] - (dep[l] << 1) + 1;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	scanf("%d", &N);
	for (int i = 1; i < N; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1, 0, -1);
	buildPar();
	long long ans = 0;
	for (int i = 1; i <= N; i++)
		for (int j = i << 1; j <= N; j += i)
			ans += getPath(i, j);
	printf("%lld\n", ans);
	return 0;
}
