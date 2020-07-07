/*
 * 319A. Malek Dance Club.cpp
 *
 *  Created on: Apr 9, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const long long MOD = 1000000007;

long long fastPower(long long base, long long power) {
	long long ret = 1;
	for (; power; power >>= 1) {
		if (power & 1)
			ret = ret * base % MOD;
		base = base * base % MOD;
	}
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	string x;
	cin >> x;
	int n = x.size();
	long long ans = fastPower(2, n - 1), pow = 1, temp = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (x[i] == '1')
			temp = (temp + pow) % MOD;
		pow = pow * 2ll % MOD;
	}
	ans = ans * temp % MOD;
	cout << ans << endl;
	return 0;
}
