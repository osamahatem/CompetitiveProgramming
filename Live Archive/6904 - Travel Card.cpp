/*
 * 6904 - Travel Card.cpp
 *
 *  Created on: Oct 2, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int n, bus[10005], train[10005];
long long dp[10005][35][35];

long long solve(int idx, int fb, int ft) {
	if (idx >= n)
		return 0;
	if (fb < 0)
		fb = 0;
	if (ft < 0)
		ft = 0;
	long long &ret = dp[idx][fb][ft];
	if (ret != -1)
		return ret;
	ret = solve(idx + 1, fb - 1, ft - 1) + (fb ? 0 : bus[idx])
			+ (ft ? 0 : 2 * train[idx]);
	ret = min(ret,
			solve(idx + 1, fb - 1, ft - 1) + 3 + (ft ? 0 : 2 * train[idx]));
	ret = min(ret, solve(idx + 1, fb - 1, ft - 1) + 6);
	ret = min(ret,
			solve(idx + 1, max(fb, 7) - 1, ft - 1) + 18
					+ (ft ? 0 : 2 * train[idx]));
	ret = min(ret, solve(idx + 1, max(fb, 7) - 1, max(ft, 7) - 1) + 36);
	ret = min(ret,
			solve(idx + 1, max(fb, 30) - 1, ft - 1) + 45
					+ (ft ? 0 : 2 * train[idx]));
	ret = min(ret, solve(idx + 1, max(fb, 30) - 1, max(ft, 30) - 1) + 90);
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
		memset(dp, -1, sizeof dp);
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d%d", &bus[i], &train[i]);
		printf("%lld\n", solve(0, 0, 0));
	}
	return 0;
}
