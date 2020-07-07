/*
 * 507D. The Maths Lecture.cpp
 *
 *  Created on: Jan 25, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

long long mod, k, n, dp[1005][105][2];

long long fastPower(long long b, long long p, long long m) {
	long long ret = 1;
	for (; p; p >>= 1) {
		if (p & 1)
			ret = ret * b % m;
		b = b * b % m;
	}
	return ret % m;
}

long long solve(int left, int kmod, bool zero) {
	if (!left) {
		if (!kmod && !zero)
			return 1;
		return 0;
	}
	long long &ret = dp[left][kmod][zero];
	if (ret != -1)
		return ret;
	ret = 0;
	if (!kmod && !zero && left < n) {
		ret = fastPower(10, left - 1, mod);
		ret = ret * 9 % mod;
		return ret;
	}
	for (int i = 0; i < 10; i++) {
		int nkmod = (fastPower(10, n - left, k) * i + kmod) % k;
		ret = (ret + solve(left - 1, nkmod, !i)) % mod;
	}
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	memset(dp, -1, sizeof dp);
	cin >> n >> k >> mod;
	cout << solve(n, 0, 0) << endl;
	return 0;
}
