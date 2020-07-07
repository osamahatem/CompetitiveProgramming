/*
 * Wet Shark and Two Subsequences.cpp
 *
 *  Created on: Jul 13, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MOD = 1e9 + 7;

int n, r, s, arr[100], dp[100][101][2001];

int solve(int idx, int len, int sum) {
	if (idx == n)
		return !len && !sum;
	int &ret = dp[idx][len][sum];
	if (ret != -1)
		return ret;
	ret = solve(idx + 1, len, sum);
	if (len && arr[idx] <= sum)
		ret = (ret + solve(idx + 1, len - 1, sum - arr[idx])) % MOD;
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin >> n >> r >> s;
	if ((r + s) & 1) {
		puts("0");
		return 0;
	}
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	memset(dp, -1, sizeof dp);
	int ans = 0, s1 = (r + s) / 2, s2 = (r - s) / 2;
	for (int i = 1; i <= n; i++)
		ans = (ans + 1ll * solve(0, i, s1) * solve(0, i, s2) % MOD) % MOD;
	cout << ans << endl;
	return 0;
}
