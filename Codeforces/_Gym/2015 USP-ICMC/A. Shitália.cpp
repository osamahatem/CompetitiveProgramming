/*
 * A. Shitália.cpp
 *
 *  Created on: Aug 30, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const double PI = acos(-1.0);

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, R, r;
	cin >> n >> R >> r;
	double ang = PI / n;
	double area = sin(ang) * r * R * n;
	cout << fixed << setprecision(6) << area << endl;
	return 0;
}
