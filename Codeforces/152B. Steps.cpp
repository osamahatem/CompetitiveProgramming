/*
 * 152B. Steps.cpp
 *
 *  Created on: Apr 12, 2016
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

	int n, m, x, y, k;
	long long ans = 0;
	scanf("%d%d%d%d%d", &n, &m, &x, &y, &k);
	while (k--) {
		int dx, dy, sx = n + m, sy = n + m;
		scanf("%d%d", &dx, &dy);
		if (dx < 0)
			sx = -x + 1;
		else if (dx > 0)
			sx = n - x;
		if (dy < 0)
			sy = -y + 1;
		else if (dy > 0)
			sy = m - y;
		if (dx)
			sx /= dx;
		if (dy)
			sy /= dy;
		int steps = min(sx, sy);
		ans += steps;
		x += steps * dx, y += steps * dy;
	}
	printf("%lld\n", ans);
	return 0;
}
