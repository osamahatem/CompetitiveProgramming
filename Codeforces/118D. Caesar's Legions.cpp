/*
 * 118D. Caesar's Legions.cpp
 *
 *  Created on: Feb 27, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MOD = 100000000;

int dp[105][105][2], k1, k2;

int solve(int n1, int n2, bool flag) {
	if (n1 + n2 == 0)
		return 1;
	if ((flag && !n2) || (!flag && !n1))
		return 0;
	int &ret = dp[n1][n2][flag];
	if (ret != -1)
		return ret;
	ret = 0;
	if (flag)
		for (int i = 1; i <= min(n2, k2); i++)
			ret = (ret + solve(n1, n2 - i, !flag)) % MOD;
	else
		for (int i = 1; i <= min(n1, k1); i++)
			ret = (ret + solve(n1 - i, n2, !flag)) % MOD;
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	memset(dp, -1, sizeof dp);
	int n1, n2;
	cin >> n1 >> n2 >> k1 >> k2;
	cout << (solve(n1, n2, 0) + solve(n1, n2, 1)) % MOD << endl;
	return 0;
}
