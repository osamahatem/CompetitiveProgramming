/*
 * 12799 - RSA.cpp
 *
 *  Created on: Nov 10, 2014
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

long long x, y, d;

void extendedEuclid(long long a, long long b) {
	if (b == 0) {
		x = 1, y = 0, d = a;
		return;
	}
	extendedEuclid(b, a % b);
	long long x1 = y;
	long long y1 = x - (a / b) * y;
	x = x1;
	y = y1;
}

long long fastPower(long long b, long long p, long long mod) {
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

	int n, e, c;
	while (cin >> n >> e >> c) {
		int p, q;
		for (int i = 3; i * i <= n; i++)
			if (n % i == 0) {
				p = i;
				q = n / p;
				break;
			}
		int fn = --p * --q;
		extendedEuclid(e, fn);
		long long inv = (x + fn) % fn;
		cout << fastPower(c, inv, n) << endl;
	}
	return 0;
}
