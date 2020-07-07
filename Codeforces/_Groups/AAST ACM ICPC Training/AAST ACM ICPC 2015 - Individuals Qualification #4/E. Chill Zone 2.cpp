/*
 * E. Chill Zone 2.cpp
 *
 *  Created on: Sep 15, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

long long dp[55][55];
int n, k;

long long solve(int idx, int left) {
	if (!left || idx < 0)
		return 0;
	if (!idx)
		return 1;
	long long &ret = dp[idx][left];
	if (ret != -1)
		return ret;
	return ret = solve(idx - 1, left - 1) + solve(idx - k, k);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	freopen("chill.in", "r", stdin);
	int T;
	cin >> T;
	while (T--) {
		memset(dp, -1, sizeof dp);
		cin >> n >> k;
		cout << solve(n, k) << endl;
	}
	return 0;
}
