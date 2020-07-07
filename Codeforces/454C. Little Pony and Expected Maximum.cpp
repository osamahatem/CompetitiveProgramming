/*
 * 454C. Little Pony and Expected Maximum.cpp
 *
 *  Created on: Jun 12, 2015
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

	int m, n;
	cin >> m >> n;
	double ans = 0.0;
	for (int i = 1; i <= m; i++) {
		double x = 1.0 / m, y = (double) (i - 1) / m;
		double temp = pow(x + y, n) - pow(y, n);
		ans += temp * i;
	}
	cout << fixed << setprecision(4) << ans << endl;
	return 0;
}
