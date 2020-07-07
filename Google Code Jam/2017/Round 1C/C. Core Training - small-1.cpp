/*
 * C. Core Training - small-1.cpp
 *
 *  Created on: Apr 30, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const double EPS = 1e-9;

int N, K;
double p[55], U;

double check(double m) {
	double ret = 0.0;
	for (int i = 0; i < N; i++)
		ret += max(0.0, m - p[i]);
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif

	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		scanf("%d%d%lf", &N, &K, &U);
		for (int i = 0; i < N; i++)
			scanf("%lf", &p[i]);
		double s = 0.0, e = 1.0;
		for (double sz = (e - s) / 2.0; sz > EPS; sz *= 0.5) {
			double mid = (s + e) / 2.0;
			if (check(mid) > U)
				e = mid;
			else
				s = mid;
		}
		double ans = 1.0;
		for (int i = 0; i < N; i++)
			ans *= max(p[i], s);
		printf("Case #%d: %.6f\n", t, ans);
	}
	return 0;
}
