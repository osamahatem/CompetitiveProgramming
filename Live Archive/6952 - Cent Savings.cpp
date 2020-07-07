/*
 * 6952 - Cent Savings.cpp
 *
 *  Created on: Sep 22, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int N, D, dp[2005][25], pr[2005];

int solve(int idx, int d) {
	if (idx == N)
		return 0;
	if (d == 0)
		return 1 << 28;
	int &ret = dp[idx][d];
	if (ret != -1)
		return ret;
	ret = 1 << 28;
	int tot = 0;
	for (int i = idx; i < N; i++) {
		tot += pr[i];
		ret = min(ret, (tot + 5) / 10 * 10 + solve(i + 1, d - 1));
	}
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	while (scanf("%d%d", &N, &D) != EOF) {
		for (int i = 0; i < N; i++)
			scanf("%d", &pr[i]);
		memset(dp, -1, sizeof dp);
		printf("%d\n", solve(0, D + 1));
	}
	return 0;
}
