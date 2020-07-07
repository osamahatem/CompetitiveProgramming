/*
 * 185A. Plant.cpp
 *
 *  Created on: Mar 29, 2015
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

	long long n;
	cin >> n;
	if (!n) {
		cout << "1" << endl;
		return 0;
	}
	long long ans = fastPower(2, 2 * n - 1) + fastPower(2, n - 1);
	cout << ans % MOD << endl;
	return 0;
}
