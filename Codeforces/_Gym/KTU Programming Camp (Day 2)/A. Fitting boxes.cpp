/*
 * A. Fitting boxes.cpp
 *
 *  Created on: May 13, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const double EPS = 1e-9;
const double PI = acos(-1.0);

bool check(double a1, double b1, double a2, double b2) {
	return a1 < a2 + EPS && b1 < b2 + EPS;
}

bool rot(double a1, double b1, double a2, double b2) {
	for (double i = 0; i < PI / 2; i += 1e-5) {
		double aa = a1 * cos(i) + b1 * sin(i);
		double bb = a1 * sin(i) + b1 * cos(i);
		if (check(aa, bb, a2, b2) || check(aa, bb, b2, a2))
			return true;
	}
	return false;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	double a1, b1, a2, b2;
	cin >> a1 >> b1 >> a2 >> b2;
	if (rot(a1, b1, a2, b2) || rot(a2, b2, a1, b1))
		return cout << "Yes" << endl, 0;
	cout << "No" << endl;
	return 0;
}
