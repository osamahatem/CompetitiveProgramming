/*
 * 759B. Travel Card.cpp
 *
 *  Created on: Jan 22, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;

int n, t[MAXN], dp[MAXN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	scanf("%d", &n);
	int idx;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &t[i]);
		dp[i] = dp[i - 1] + 20;
		idx = max(0, upper_bound(t, t + i, t[i] - 90) - t - 1);
		dp[i] = min(dp[i], dp[idx] + 50);
		idx = max(0, upper_bound(t, t + i, t[i] - 1440) - t - 1);
		dp[i] = min(dp[i], dp[idx] + 120);
		printf("%d\n", dp[i] - dp[i - 1]);
	}
	return 0;
}
