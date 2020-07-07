/*
 * 104 - Arbitrage.cpp
 *
 *  Created on: Sep 15, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const double LIM = 1.01;

int n, best[21][20][20];
double rate[20][20], dist[21][20][20];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	while (scanf("%d", &n) != EOF) {
		for (int k = 0; k <= n; k++)
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					dist[k][i][j] = 0.0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == j) {
					rate[i][i] = 0.0;
					dist[0][i][i] = dist[1][i][i] = 0.0, best[0][i][i] = i;
				} else {
					scanf("%lf", &rate[i][j]);
					dist[1][i][j] = rate[i][j], best[1][i][j] = j;
				}
			}
		}
		for (int l = 2; l <= n; l++)
			for (int k = 0; k < n; k++)
				for (int i = 0; i < n; i++)
					for (int j = 0; j < n; j++)
						if (rate[i][k] * dist[l - 1][k][j] > dist[l][i][j]) {
							dist[l][i][j] = rate[i][k] * dist[l - 1][k][j];
							best[l][i][j] = k;
						}
		bool found = 0;
		for (int l = 2; l <= n; l++) {
			for (int i = 0; i < n && !found; i++) {
				if (dist[l][i][i] > LIM) {
					found = 1;
					printf("%d", i + 1);
					int u = i, ll = l;
					do {
						u = best[ll][u][i];
						ll--;
						printf(" %d", u + 1);
					} while (ll);
					printf("\n");
				}
			}
		}
		if (!found)
			printf("no arbitrage sequence exists\n");
	}
	return 0;
}
