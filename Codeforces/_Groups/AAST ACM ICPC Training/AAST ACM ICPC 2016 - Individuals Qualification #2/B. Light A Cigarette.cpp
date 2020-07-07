/*
 * B. Light A Cigarette.cpp
 *
 *  Created on: Aug 31, 2016
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

//	freopen("light.in", "r", stdin);
	int T;
	scanf("%d", &T);
	while (T--) {
		double x, ans = 0.0;
		int n;
		scanf("%d", &n);
		while (n--) {
			scanf("%lf", &x);
			ans += 1.0 - x;
		}
		printf("%.4f\n", ans);
	}
	return 0;
}
