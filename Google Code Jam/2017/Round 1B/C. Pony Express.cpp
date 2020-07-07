/*
 * C. Pony Express.cpp
 *
 *  Created on: Apr 22, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const long long INF = 1e15;

int N, Q, E[105], S[105];
long long dist[105][105];
double ans[105][105];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif

	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		scanf("%d%d", &N, &Q);
		for (int i = 1; i <= N; i++)
			scanf("%d%d", &E[i], &S[i]);
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				scanf("%lld", &dist[i][j]);
				dist[i][j] = (i == j ? 0 : dist[i][j]);
				dist[i][j] = (dist[i][j] == -1 ? INF : dist[i][j]);
			}
		}
		for (int k = 1; k <= N; k++)
			for (int i = 1; i <= N; i++)
				for (int j = 1; j <= N; j++)
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++)
				if (dist[i][j] <= E[i])
					ans[i][j] = 1.0 * dist[i][j] / S[i];
				else
					ans[i][j] = INF;
		}
		for (int k = 1; k <= N; k++)
			for (int i = 1; i <= N; i++)
				for (int j = 1; j <= N; j++)
					ans[i][j] = min(ans[i][j], ans[i][k] + ans[k][j]);
		printf("Case #%d:", t);
		while (Q--) {
			int u, v;
			scanf("%d%d", &u, &v);
			printf(" %.6f", ans[u][v]);
		}
		printf("\n");
	}
	return 0;
}
