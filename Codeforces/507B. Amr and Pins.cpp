/*
 * 507B. Amr and Pins.cpp
 *
 *  Created on: Jan 24, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const double EPS = 1e-9;

double dist(int x1, int y1, int x2, int y2) {
	long long dx = x1 - x2, dy = y1 - y2;
	return sqrt(dx * dx + dy * dy);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int r, x1, y1, x2, y2, ans = 0;
	cin >> r >> x1 >> y1 >> x2 >> y2;
	r *= 2;
	double d = dist(x1, y1, x2, y2);
	double temp = d / r;
	if (d - floor(temp) * r > EPS)
		ans++;
	ans += (int) (floor(temp) + EPS);
	cout << ans << endl;
	return 0;
}
