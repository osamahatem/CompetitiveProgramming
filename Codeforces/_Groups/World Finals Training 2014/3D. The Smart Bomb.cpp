/*
 * 3D. The Smart Bomb.cpp
 *
 *  Created on: Jan 28, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const double EPS = 1e-9;

double dist(int x1, int y1, int x2, int y2) {
	double dx = x1 - x2, dy = y1 - y2;
	return sqrt(dx * dx + dy * dy);
}

int main() {
//#ifndef ONLINE_JUDGE
	freopen("bomb.in", "r", stdin);
	freopen("bomb.out", "w", stdout);
//#endif

	int x1, x2, x3, y1, y2, y3;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	double d1 = dist(x1, y1, x2, y2), d2 = dist(x1, y1, x3, y3);
	double d3 = dist(x2, y2, x3, y3);
	double r1 = (d1 + d2 - d3) / 2.0;
	double r2 = (d1 + d3 - d2) / 2.0;
	double r3 = (d2 + d3 - d1) / 2.0;
	cout << fixed << setprecision(9);
	cout << r1 << endl << r2 << endl << r3 << endl;
	return 0;
}
