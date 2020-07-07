/*
 * 304D. Rectangle Puzzle II.cpp
 *
 *  Created on: Dec 4, 2014
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

	int n, m, x, y, a, b;
	cin >> n >> m >> x >> y >> a >> b;
	int g = __gcd(a, b);
	a /= g;
	b /= g;
	int maxi = min(n / a, m / b);
	int x1 = 0, x2 = maxi * a, y1 = 0, y2 = maxi * b;
	int cx = (x2 + 1) / 2, cy = (y2 + 1) / 2;
	if (cx < x) {
		int shift = min(x - cx, n - x2);
		x1 += shift;
		x2 += shift;
	}
	if (cy < y) {
		int shift = min(y - cy, m - y2);
		y1 += shift;
		y2 += shift;
	}
	cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
	return 0;
}
