/*
 * 344C. Rational Resistance.cpp
 *
 *  Created on: Feb 6, 2015
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

	long long a, b, ans = 0;
	cin >> a >> b;
	while (b && a % b) {
		if (a > b) {
			ans += (a - a % b) / b;
			a %= b;
		} else {
			ans += b / a;
			b -= b / a * a;
		}
	}
	if (b)
		ans += a / b;
	cout << ans << endl;
	return 0;
}
