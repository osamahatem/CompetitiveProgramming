/*
 * A. Steed 2 - Cruise Control.cpp
 *
 *  Created on: Apr 22, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif

	int T, D, N;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		scanf("%d%d", &D, &N);
		double ans = 0.0;
		for (int i = 0; i < N; i++) {
			int k, s;
			scanf("%d%d", &k, &s);
			ans = max(ans, 1.0 * (D - k) / s);
		}
		printf("Case #%d: %.6f\n", t, 1.0 * D / ans);
	}
	return 0;
}
