/*
 * 6327 - Math Homework.cpp
 *
 *  Created on: Nov 10, 2014
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const long long MOD = 1000000007;

long long fastPow(long long b, long long p, long long mod) {
	long long ret = 1;
	for (; p; p >>= 1) {
		if (p & 1)
			ret = ret * b % mod;
		b = b * b % mod;
	}
	return ret;
}

long long modInv(long long x) {
	return fastPow(x, MOD - 2, MOD);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int t, div[7];
	long long n;
	scanf("%d", &t);
	while (t--) {
		long long ans = 0;
		int cntD = 0;
		vector<int> notDiv;
		scanf("%lld", &n);
		for (int i = 1; i <= 6; i++) {
			scanf("%1d", &div[i]);
			if (div[i] == 1 || div[i] == 2)
				cntD++;
			if (div[i] == 0)
				notDiv.push_back(i);
		}
		if (cntD == 6)
			ans++;
		long long tot = fastPow(10, n, MOD);
		int lcm1 = 1;
		for (int i = 1; i <= 6; i++)
			if (div[i] == 1)
				lcm1 = lcm1 * i / __gcd(lcm1, i);
		ans = (ans + (tot - fastPow(10, n, lcm1)) * modInv(lcm1) % MOD) % MOD;
		if (fastPow(10, n, lcm1) == 0)
			ans = (ans - 1 + MOD) % MOD;
		int sz = notDiv.size();
		for (int i = 1; i < (1 << sz); i++) {
			int lcm0 = 1, c = 0;
			for (int j = 0; j < sz; j++) {
				if (i & (1 << j)) {
					c++;
					lcm0 = lcm0 * notDiv[j] / __gcd(lcm0, notDiv[j]);
				}
			}
			lcm0 = lcm1 * lcm0 / __gcd(lcm0, lcm1);
			long long temp = (tot - fastPow(10, n, lcm0)) * modInv(lcm0) % MOD;
			if (c % 2 == 0) {
				ans = (ans + temp) % MOD;
				if (fastPow(10, n, lcm0) == 0)
					ans = (ans - 1 + MOD) % MOD;
			} else {
				ans = (ans - temp + MOD) % MOD;
				if (fastPow(10, n, lcm0) == 0)
					ans = (ans + 1) % MOD;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
