/*
 * 7054 - Osu!.cpp
 *
 *  Created on: Oct 10, 2015
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

	int T;
	scanf("%d", &T);
	while (T--) {
		int t, x, y, lt, lx, ly, n;
		double ans = 0.0;
		scanf("%d%d%d%d", &n, &t, &x, &y);
		n--;
		while (n--) {
			lx = x, ly = y, lt = t;
			scanf("%d%d%d", &t, &x, &y);
			int dx = x - lx, dy = y - ly;
			double dist = sqrt(1ll * dx * dx + 1ll * dy * dy);
			ans = max(ans, dist / (t - lt));
		}
		printf("%.9f\n", ans);
	}
	return 0;
}
