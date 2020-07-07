/*
 * 6954 - Euclidean TSP.cpp
 *
 *  Created on: Sep 22, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

double n, p, s, v;

double check(double c) {
	double runn = (n / (p * 1e9)) * pow(log(n) / log(2.0), c * sqrt(2));
	double timm = s * (1.0 + 1.0 / c) / v;
	return runn + timm;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	while (scanf("%lf%lf%lf%lf", &n, &p, &s, &v) != EOF) {
		double s = 0.0, e = 100.0;
		int k = 0;
		while (k++ < 200) {
			double m1 = (s + s + e) / 3.0, m2 = (s + e + e) / 3.0;
			if (check(m1) < check(m2))
				e = m2;
			else
				s = m1;
		}
		assert(check(s) < 1e18);
		printf("%.7f %.7f\n", check(s), s);
	}
	return 0;
}
