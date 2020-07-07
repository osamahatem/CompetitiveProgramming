/*
 * 700A. As Fast As Possible.cpp
 *
 *  Created on: Jul 22, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const double EPS = 1e-9;

int n, l, v1, v2, k;

bool check(double T) {
	int trips = (n + k - 1) / k;
	double pos = 0.0;
	while (trips) {
		double t = (l - pos - T * v1) / (v2 - v1);
		if (t > T)
			return false;
		double p2 = t * v2 + pos;
		pos += t * v1;
		T -= t;
		t = (p2 - pos) / (v1 + v2);
		pos += t * v1;
		T -= t;
		trips--;
	}
	return true;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin >> n >> l >> v1 >> v2 >> k;
	double s = 0.0;
	for (double sz = l / 2.0 / v1; sz > EPS; sz *= 0.5) {
		double mid = s + sz;
		if (!check(mid))
			s += sz;
	}
	cout << fixed << setprecision(6) << s << endl;
	return 0;
}
