/*
 * 621D. Rat Kwesh and Cheese.cpp
 *
 *  Created on: Mar 15, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const double EPS = 1e-9;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	double x, y, z;
	string ans = "";
	cin >> x >> y >> z;
	if (x - 1.0 < EPS && y - 1.0 < EPS && z - 1.0 < EPS) {
		double mini = 1e9, temp;
		double ix = 1 / x, iy = 1 / y, iz = 1 / z;

		temp = z * log(y) + log(log(ix));
		if (mini - temp > EPS)
			mini = temp, ans = "x^y^z";
		temp = y * log(z) + log(log(ix));
		if (mini - temp > EPS)
			mini = temp, ans = "x^z^y";
		temp = log(y) + log(z) + log(log(ix));
		if (mini - temp > EPS)
			mini = temp, ans = "(x^y)^z";

		temp = z * log(x) + log(log(iy));
		if (mini - temp > EPS)
			mini = temp, ans = "y^x^z";
		temp = x * log(z) + log(log(iy));
		if (mini - temp > EPS)
			mini = temp, ans = "y^z^x";
		temp = log(x) + log(z) + log(log(iy));
		if (mini - temp > EPS)
			mini = temp, ans = "(y^x)^z";

		temp = y * log(x) + log(log(iz));
		if (mini - temp > EPS)
			mini = temp, ans = "z^x^y";
		temp = x * log(y) + log(log(iz));
		if (mini - temp > EPS)
			mini = temp, ans = "z^y^x";
		temp = log(x) + log(y) + log(log(iz));
		if (mini - temp > EPS)
			mini = temp, ans = "(z^x)^y";
	} else {
		double maxi = -1e9, temp;

		if (x > 1.0) {
			temp = z * log(y) + log(log(x));
			if (temp - maxi > EPS)
				maxi = temp, ans = "x^y^z";
			temp = y * log(z) + log(log(x));
			if (temp - maxi > EPS)
				maxi = temp, ans = "x^z^y";
			temp = log(y) + log(z) + log(log(x));
			if (temp - maxi > EPS)
				maxi = temp, ans = "(x^y)^z";
		}

		if (y > 1.0) {
			temp = z * log(x) + log(log(y));
			if (temp - maxi > EPS)
				maxi = temp, ans = "y^x^z";
			temp = x * log(z) + log(log(y));
			if (temp - maxi > EPS)
				maxi = temp, ans = "y^z^x";
			temp = log(x) + log(z) + log(log(y));
			if (temp - maxi > EPS)
				maxi = temp, ans = "(y^x)^z";
		}

		if (z > 1.0) {
			temp = y * log(x) + log(log(z));
			if (temp - maxi > EPS)
				maxi = temp, ans = "z^x^y";
			temp = x * log(y) + log(log(z));
			if (temp - maxi > EPS)
				maxi = temp, ans = "z^y^x";
			temp = log(x) + log(y) + log(log(z));
			if (temp - maxi > EPS)
				maxi = temp, ans = "(z^x)^y";
		}
	}
	cout << ans << endl;
	return 0;
}
