/*
 * 894B. Ralph And His Magic Field.cpp
 *
 *  Created on: Nov 21, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MOD = 1e9 + 7;

long long fastPower(long long b, long long p) {
	long long ret = 1;
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

	long long n, m;
	int k;
	cin >> n >> m >> k;
	cout
			<< (((n ^ m) & 1) && k == -1 ?
					0 : fastPower(fastPower(2, n - 1), m - 1)) << endl;
	return 0;
}
