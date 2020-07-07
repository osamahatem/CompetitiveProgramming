/*
 * 486A. Calculating Function.cpp
 *
 *  Created on: Nov 19, 2014
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
//	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	long long x;
	cin >> x;
	long long ans = ++x / 2;
	if (--x % 2)
		ans *= -1;
	cout << ans << endl;
	return 0;
}
