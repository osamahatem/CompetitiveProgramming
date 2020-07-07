/*
 * 190B. Surrounded.cpp
 *
 *  Created on: Apr 16, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const double INF = 1e10;
const double EPS = 1e-9;

double dist(int x1, int x2, int y1, int y2) {
	double dx = fabs(x1 - x2), dy = fabs(y1 - y2);
	return hypot(dx, dy);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int x1, y1, r1, x2, y2, r2;
	cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
	double d[2][2], c = dist(x1, x2, y1, y2), ans = INF;
	d[0][0] = -r1, d[0][1] = r1;
	d[1][0] = c - r2, d[1][1] = c + r2;
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			ans = min(ans, EPS + fabs(d[0][i] - d[1][j]) / 2.0);
	if (c < r1 + r2 && c > (double) max(r1, r2) / 2.0)
		ans = 0.0;
	cout << fixed << setprecision(9) << ans << endl;
	return 0;
}
