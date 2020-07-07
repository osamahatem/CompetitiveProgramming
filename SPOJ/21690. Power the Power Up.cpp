/*
 * 21690. Power the Power Up.cpp
 *
 *  Created on: Nov 6, 2014
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const long long MOD = 1000000007;

long long fastPower(long long base, long long power, long long mod) {
	long long ret = 1;
	for (; power; power >>= 1) {
		if (power & 1)
			ret = ret * base % mod;
		base = base * base % mod;
	}
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	long long a, b, c;
	while (cin >> a >> b >> c, a != -1) {
		a %= MOD;
		long long pow = fastPower(b, c, MOD - 1);
		if (a == 0 && b == 0 && c != 0)
			cout << "1\n";
		else if (a == 0 && pow == 0)
			cout << "0\n";
		else
			cout << fastPower(a, pow, MOD) << endl;
	}
	return 0;
}
