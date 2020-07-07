/*
 * A. Equilaterals Intersection.cpp
 *
 *  Created on: Sep 25, 2016
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

	freopen("equilaterals.in", "r", stdin);
	int T;
	scanf("%d", &T);
	while (T--) {
		int n, s;
		scanf("%d%d", &n, &s);
		double ang = PI / (3.0 * n);
		double h = s / (sqrt(3.0) * 2.0);
		double b = h * tan(ang);
		double ans = h * b * 3.0 * n;
		printf("%.4f\n", ans);
	}
	return 0;
}
