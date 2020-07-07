/*
 * 300C. Beautiful Numbers.cpp
 *
 *  Created on: Dec 1, 2014
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const long long MOD = 1000000007;

long long fact[1000005];

long long fastPower(long long b, long long p) {
	int ret = 1;
	for (; p; p >>= 1) {
		if (p & 1)
			ret = ret * b % MOD;
		b = b * b % MOD;
	}
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int a, b, n;
	cin >> a >> b >> n;
	fact[0] = 1;
	for (int i = 1; i <= n; i++)
		fact[i] = fact[i - 1] * i % MOD;

	long long ans = 0;
	for (int i = 0; i <= n; i++) {
		int sum = a * i + b * (n - i);
		bool flag = 0;
		while (sum) {
			if (sum % 10 != a && sum % 10 != b)
				flag = 1;
			sum /= 10;
		}
		if (flag)
			continue;
		long long temp = fact[i] * fact[n - i] % MOD;
		temp = fastPower(temp, MOD - 2);
		temp = temp * fact[n] % MOD;
		ans = (ans + temp) % MOD;
	}
	cout << ans << endl;
	return 0;
}
