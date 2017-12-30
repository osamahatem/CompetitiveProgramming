/*
 * 12300 - Smallest Regular Polygon.cpp
 *
 *  Created on: Dec 14, 2017
 *      Author: Osama Hatem
 */
 
/*
Line AB is the diameter of the polygon. This can be used to calculate the side
length, and then the area. Triangle is a special case.
*/

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

typedef long double myf;

const myf PI = acosl(-1.0L);

myf dist(int x1, int y1, int x2, int y2) {
	int dx = x2 - x1, dy = y2 - y1;
	return sqrtl(dx * dx + dy * dy);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int x1, y1, x2, y2, n;
	while (scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &n), n) {
		myf int_ang = PI * (n - 2) / n;
		myf dst = dist(x1, y1, x2, y2);
		myf side = 0.0;
		if (n == 3) {
			side = dst;
		} else if (n & 1) {
			int nn = n / 2;
			myf ang = (PI - int_ang) * (nn - 1) / 2.0L;
			ang = int_ang - ang;
			side = dst * cosl(ang) / cosl(int_ang / 2.0L);
		} else {
			side = dst / 2.0L;
		}
		myf ans = side * side * sinl(PI - int_ang) / 2.0L;
		if (n != 3)
			ans *= n;
		printf("%.6Lf\n", ans);
	}
	return 0;
}
