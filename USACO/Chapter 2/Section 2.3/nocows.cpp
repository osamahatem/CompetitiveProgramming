/*
 ID: 19semse1
 PROG: nocows
 LANG: C++
 */
/*
 * nocows.cpp
 *
 *  Created on: Mar 10, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MOD = 9901;

int dp[205][105][2];

int solve(int n, int k, bool flag) {
	if (!k)
		return 0;
	if (n == 1) {
		if ((flag && k == 1) || (!flag && k > 1))
			return 1;
		return 0;
	}
	int &ret = dp[n][k][flag];
	if (ret != -1)
		return ret;
	ret = 0;
	n--;
	for (int i = 1; i < n; i++) {
		if (flag) {
			ret += solve(i, k - 1, flag) * solve(n - i, k - 1, flag) % MOD;
			ret += solve(i, k - 1, flag) * solve(n - i, k - 1, 0) % MOD;
			ret += solve(i, k - 1, 0) * solve(n - i, k - 1, flag) % MOD;
		}
		if (!flag)
			ret += solve(i, k - 1, 0) * solve(n - i, k - 1, 0) % MOD;
	}
	ret %= MOD;
	return ret;
}

int main() {
//#ifndef ONLINE_JUDGE
	freopen("nocows.in", "r", stdin);
	freopen("nocows.out", "w", stdout);
//#endif

	memset(dp, -1, sizeof dp);
	int n, k;
	cin >> n >> k;
	cout << solve(n, k, 1) << endl;
	return 0;
}
