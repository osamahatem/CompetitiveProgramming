/*
 * 9972. The SKey.cpp
 *
 *  Created on: Nov 6, 2014
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

long long fastPow(long long base, long long power, long long mod) {
	long long ret = 1;
	for (; power; power >>= 1) {
		if (power & 1)
			ret = ret * base % mod;
		base = base * base % mod;
	}
	return ret;
}

long long multInv(long long denom, long long mod) {
	return fastPow(denom, mod - 2, mod);
}

long long sumOfPow(long long base, long long power, long long mod) {
	if (base == 1)
		return base * ++power % mod;
	long long ret = (fastPow(base, power + 1, mod) - 1 + mod) % mod;
	ret = ret * multInv(base - 1, mod) % mod;
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int t, tc = 0;
	cin >> t;
	while (t--) {
		long long a, n, p, m, ans;
		cin >> a >> n >> p >> m;
		ans = m * sumOfPow(multInv(a, p), n, p) % p;
		cout << "Case " << ++tc << ": " << ans << endl;
	}
	return 0;
}
