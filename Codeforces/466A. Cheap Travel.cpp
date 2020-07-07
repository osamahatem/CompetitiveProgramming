/*
 * 466A. Cheap Travel.cpp
 *
 *  Created on: Jun 21, 2015
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

	int n, m, a, b, ans = 0;
	cin >> n >> m >> a >> b;
	if (b < m * a) {
		ans += n / m * b;
		n -= n / m * m;
		ans += min(n * a, b);
	} else
		ans += n * a;
	cout << ans << endl;
	return 0;
}
