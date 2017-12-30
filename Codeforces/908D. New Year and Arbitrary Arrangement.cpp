/*
 * 908D. New Year and Arbitrary Arrangement.cpp
 *
 *  Created on: Dec 29, 2017
 *      Author: Osama Hatem
 */
 
/*
http://codeforces.com/blog/entry/56713
*/

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MOD = 1e9 + 7;

long long dp[1005][1005], pa, pb;
int k;

long long fastPower(long long b, long long p) {
	long long ret = 1;
	for (; p; p >>= 1) {
		if (p & 1)
			ret = ret * b % MOD;
		b = b * b % MOD;
	}
	return ret;
}

long long solve(int a, int rem) {
	long long &ret = dp[a][rem];
	if (~ret)
		return ret;
	if (a >= rem) {
		ret = (a + fastPower(pb, MOD - 2) - 1) % MOD;
	} else {
		ret = pa * solve(a + 1, rem) % MOD;
		ret = (pb * (a + solve(a, rem - a)) % MOD + ret) % MOD;
	}
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	memset(dp, -1, sizeof dp);
	cin >> k >> pa >> pb;
	int sum = pa + pb;
	pa = pa * fastPower(sum, MOD - 2) % MOD;
	pb = pb * fastPower(sum, MOD - 2) % MOD;
	cout << solve(1, k) << endl;
	return 0;
}
