/*
 * 12704 - Little Masters.cpp
 *
 *  Created on: Aug 9, 2014
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

	int t;
	scanf("%d", &t);
	while (t--) {
		double x, y, r;
		scanf("%lf%lf%lf", &x, &y, &r);
		double dist = sqrt(x * x + y * y);
		printf("%.2f %.2f\n", r - dist, r + dist);
	}
	return 0;
}
