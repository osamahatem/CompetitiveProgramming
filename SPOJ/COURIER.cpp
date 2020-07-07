/*
 * COURIER.cpp
 *
 *  Created on: Sep 15, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int INF = 63 * (1 + (1 << 8) + (1 << 16) + (1 << 24));

int n, m, h, z, dist[101][101], dp[12][1 << 12];
int cnt, orderU[12], orderV[12];

int solve(int last, int mask) {
	int cur = mask ? orderV[last] : h;
	if (mask == (1 << cnt) - 1)
		return dist[cur][h];
	int& ret = dp[last][mask];
	if (~ret)
		return ret;
	ret = 1 << 30;
	for (int i = 0; i < cnt; i++) {
		if (mask & (1 << i))
			continue;
		int u = orderU[i], v = orderV[i];
		ret = min(ret, dist[cur][u] + dist[u][v] + solve(i, mask | (1 << i)));
	}
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d%d", &n, &m, &h);
		memset(dist, 63, sizeof dist);
		memset(dp, -1, sizeof dp), cnt = 0;
		for (int i = 1; i <= n; i++)
			dist[i][i] = 0;
		while (m--) {
			int u, v, c;
			scanf("%d%d%d", &u, &v, &c);
			dist[u][v] = min(dist[u][v], c);
			dist[v][u] = min(dist[v][u], c);
		}
		for (int k = 1; k <= n; k++)
			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= n; j++)
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
		scanf("%d", &z);
		while (z--) {
			int u, v, b;
			scanf("%d%d%d", &u, &v, &b);
			while (b--) {
				orderU[cnt] = u;
				orderV[cnt++] = v;
			}
		}
		printf("%d\n", solve(0, 0));
	}
	return 0;
}
