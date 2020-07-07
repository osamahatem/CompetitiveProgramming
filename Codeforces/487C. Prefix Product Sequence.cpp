/*
 * 487C. Prefix Product Sequence.cpp
 *
 *  Created on: Jul 14, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

long long fastPower(long long b, long long p, int mod) {
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

	int n;
	cin >> n;
	if (n == 1) {
		cout << "YES\n1" << endl;
		return 0;
	}
	if (n == 4) {
		cout << "YES\n1\n3\n2\n4" << endl;
		return 0;
	}
	for (int i = 2; i * i <= n; i++)
		if (n % i == 0) {
			cout << "NO" << endl;
			return 0;
		}
	cout << "YES\n1" << endl;
	for (int i = 2; i < n; i++)
		cout << (long long) i * fastPower(i - 1, n - 2, n) % n << endl;
	cout << n << endl;
	return 0;
}
