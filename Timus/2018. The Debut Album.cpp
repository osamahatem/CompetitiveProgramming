/*
 * 2018. The Debut Album.cpp
 *
 *  Created on: Nov 8, 2014
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const long long MOD = 1000000007;

long long dp[50005][2];
int n, a, b;

long long solve(int idx, bool song) {
	if (idx < 0)
		return 0;
	if (idx == 0)
		return 1;
	long long &ret = dp[idx][song];
	if (ret != -1)
		return ret;
	ret = 0;
	int maxi = (song ? a : b);
	for (int i = 1; i <= maxi; i++)
		ret = (ret + solve(idx - i, !song)) % MOD;
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	memset(dp, -1, sizeof dp);
	cin >> n >> a >> b;
	cout << (solve(n, 0) + solve(n, 1)) % MOD << endl;
	return 0;
}
