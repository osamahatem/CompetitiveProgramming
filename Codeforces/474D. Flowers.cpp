/*
 * 474D. Flowers.cpp
 *
 *  Created on: Feb 19, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;
const int MOD = 1000000007;

int dp[MAXN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, k, a, b;
	cin >> n >> k;
	dp[0] = 1;
	for (int i = 1; i < MAXN; i++) {
		dp[i] = dp[i - 1];
		if (i - k >= 0)
			dp[i] = (dp[i] + dp[i - k]) % MOD;
	}
	dp[0] = 0;
	for (int i = 1; i < MAXN; i++)
		dp[i] = (dp[i] + dp[i - 1]) % MOD;
	while (n--) {
		cin >> a >> b;
		int ans = (dp[b] - dp[a - 1] + MOD) % MOD;
		cout << ans << endl;
	}
	return 0;
}
