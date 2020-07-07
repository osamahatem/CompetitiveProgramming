/*
 * 194B. Square.cpp
 *
 *  Created on: May 18, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//  freopen("out.out", "w", stdout);
#endif

	int t;
	long long n, lcm;
	cin >> t;
	while (t--) {
		cin >> n;
		lcm = n * 4 * (n + 1) / __gcd(n + 1, n * 4);
		cout << lcm / (n + 1) + 1 << endl;
	}
	return 0;
}
