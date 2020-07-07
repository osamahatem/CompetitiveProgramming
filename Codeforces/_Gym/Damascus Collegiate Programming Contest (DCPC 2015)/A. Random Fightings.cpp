/*
 * A. Random Fightings.cpp
 *
 *  Created on: Feb 13, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int n, vis[1 << 20], id;
double p[20][20], dp[1 << 20];

double solve(int mask) {
	if (mask == (1 << n) - 1)
		return 1.0;
	if (vis[mask] == id)
		return dp[mask];
	vis[mask] = id;
	double ret = 0.0;
	int left = __builtin_popcount(mask);
	int poss = left * (left + 1) / 2;
	for (int i = 0; i < n; i++)
		if (mask & (1 << i))
			for (int j = 0; j < n; j++)
				if (i != j && !(mask & (1 << j)))
					ret += solve(mask | (1 << j)) * p[i][j] / poss;
	return dp[mask] = ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		id++;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				scanf("%lf", &p[i][j]);
		printf("Case %d:", t);
		for (int i = 0; i < n; i++)
			printf(" %.6f", solve(1 << i));
		printf("\n");
	}
	return 0;
}
