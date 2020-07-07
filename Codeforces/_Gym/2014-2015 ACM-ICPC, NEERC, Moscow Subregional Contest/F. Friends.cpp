/*
 * F. Friends.cpp
 *
 *  Created on: Oct 4, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int S = 9 * 3600;

double dist(int x1, int y1, int x2, int y2) {
	int dx = x1 - x2, dy = y1 - y2;
	return sqrt(dx * dx + dy * dy);
}

bool check(int xa, int ya, int xb, int yb, int xc, int yc) {
	return (yb - yc) * (xc - xa) == (yc - ya) * (xb - xc);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int xa, ya, xb, yb, xc, yc, d, v;
	scanf("%d%d%d%d%d%d%d%d", &xa, &ya, &xb, &yb, &xc, &yc, &d, &v);
	double t[3];
	t[0] = (dist(xa, ya, xc, yc) + dist(xc, yc, xb, yb)) / v * 3600 + d * 60;
	t[0] += S;
	int h, m;
	scanf("%d:%d", &h, &m);
	t[1] = h * 3600 + m * 60;
	scanf("%d:%d", &h, &m);
	t[1] += h * 3600 + m * 60;
	int w;
	scanf("%d", &w);
	t[2] = S + dist(xa, ya, xb, yb) / w * 3600;
	if (check(xa, ya, xb, yb, xc, yc))
		t[2] += d * 60;
	if (t[0] < t[1] && t[0] < t[2])
		printf("Alex\n");
	else if (t[1] < t[0] && t[1] < t[2])
		printf("Dmitry\n");
	else
		printf("Petr\n");
	return 0;
}
