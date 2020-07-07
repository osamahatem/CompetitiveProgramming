/*
 * 11718 - Fantasy of a Summation.cpp
 *
 *  Created on: Oct 2, 2014
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

long long mod;

long long fastPower(int b, int p) {
	long long ret = 1;
	for (; p; p >>= 1) {
		if (p & 1)
			ret = ret * b % mod;
		b = b * b % mod;
	}
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
		long long n, k, x;
		cin >> n >> k >> mod;
		long long ans = 0;
		for (int i = 0; i < n; i++) {
			cin >> x;
			ans = (ans + x) % mod;
		}
		ans = ans * fastPower(n, k - 1) % mod;
		ans = ans * k % mod;
		cout << "Case " << ++tc << ": " << ans << "\n";
	}
	return 0;
}
