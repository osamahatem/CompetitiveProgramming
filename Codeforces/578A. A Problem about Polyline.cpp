/*
 * 578A. A Problem about Polyline.cpp
 *
 *  Created on: Sep 16, 2015
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

	long long x, y;
	cin >> x >> y;
	if (y > x) {
		cout << "-1" << endl;
		return 0;
	}
	double ans = y;
	long long temp = (x + y - 1) / y;
	if (temp % 2 == 0 || temp == x / y) {
		long long xx = 1ll * temp * y, yy = (temp % 2 ? y : 0);
		ans += (double) (abs(y - yy) - abs(x - xx)) / temp;
	} else {
		temp--;
		long long xx = 1ll * temp * y, yy = (temp % 2 ? y : 0);
		ans += (double) (abs(y - yy) + abs(x - xx)) / temp;
	}
	cout << fixed << setprecision(9) << ans << endl;
	return 0;
}
