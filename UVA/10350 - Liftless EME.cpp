/*
 * 10350 - Liftless EME.cpp
 *
 *  Created on: Sep 18, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

char name[15];
int n, m, cost[120][15][15], dp[120][15];

int solve(int f, int h) {
	if (f == n - 1)
		return 0;
	int& ret = dp[f][h];
	if (~ret)
		return ret;
	ret = 1 << 30;
	for (int i = 0; i < m; i++)
		ret = min(ret, solve(f + 1, i) + cost[f][h][i]);
	ret += 2;
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	while (scanf("%s", name) != EOF) {
		memset(dp, -1, sizeof dp);
		scanf("%d%d", &n, &m);
		for (int i = 0; i + 1 < n; i++)
			for (int j = 0; j < m; j++)
				for (int k = 0; k < m; k++)
					scanf("%d", &cost[i][j][k]);
		int ans = 1 << 30;
		for (int i = 0; i < m; i++)
			ans = min(ans, solve(0, i));
		printf("%s\n%d\n", name, ans);
	}
	return 0;
}
