/*
 * 598A. Tricky Sum.cpp
 *
 *  Created on: Nov 13, 2015
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

	int t;
	cin >> t;
	while (t--) {
		long long n, sum;
		cin >> n;
		sum = n * (n + 1) / 2;
		for (int i = 1; i <= n; i *= 2)
			sum -= 2ll * i;
		cout << sum << endl;
	}
	return 0;
}
