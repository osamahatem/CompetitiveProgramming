/*
 * 483A. Counterexample.cpp
 *
 *  Created on: Jul 13, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	long long l, r;
	cin >> l >> r;
	for (long long a = l; a <= r; a++)
		for (long long b = a + 1; b <= r; b++)
			for (long long c = b + 1; c <= r; c++)
				if (__gcd(a, b) == 1 && __gcd(b, c) == 1 && __gcd(a, c) != 1) {
					cout << a << " " << b << " " << c << endl;
					return 0;
				}
	cout << "-1" << endl;
	return 0;
}
