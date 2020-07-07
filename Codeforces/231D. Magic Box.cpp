/*
 * 231D. Magic Box.cpp
 *
 *  Created on: Feb 28, 2015
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

	int x, y, z, x1, y1, z1, a1, a2, a3, a4, a5, a6, ans = 0;
	cin >> x1 >> y1 >> z1 >> x >> y >> z;
	cin >> a1 >> a2 >> a3 >> a4 >> a5 >> a6;
	if (y1 < 0)
		ans += a1;
	if (y1 > y)
		ans += a2;
	if (z1 < 0)
		ans += a3;
	if (z1 > z)
		ans += a4;
	if (x1 < 0)
		ans += a5;
	if (x1 > x)
		ans += a6;
	cout << ans << endl;
	return 0;
}
