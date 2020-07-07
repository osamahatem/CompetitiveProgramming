/*
 * H. Annuity Payment Scheme.cpp
 *
 *  Created on: Nov 16, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const double EPS = 1e-9;

int s, m, p;

bool check(double x) {
	double cur = s;
	for (int i = 0; i < m && cur > 0.0; i++)
		cur -= x - cur * p / 100.0;
	return cur > 0.0 ? false : true;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin >> s >> m >> p;
	double a = 1.0 * s * p / 100.0, b = 2.0 * s;
	for (double sz = (b - a) / 2.0; sz > EPS; sz *= 0.5) {
		double mid = a + sz;
		if (!check(mid))
			a += sz;
	}
	cout << fixed << setprecision(5) << a << endl;
	return 0;
}
