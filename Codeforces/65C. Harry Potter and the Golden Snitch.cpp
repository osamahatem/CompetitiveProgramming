/*
 * 65C. Harry Potter and the Golden Snitch.cpp
 *
 *  Created on: Dec 14, 2017
 *      Author: Osama Hatem
 */
 
/*
Since vp >= vs, the time value can be obtained through binary search; if the ball
is caught at time t, it can be caught at any time t2 >= t.
*/

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e4 + 5;
const double EPS = 1e-11;

struct point {
	double x, y, z;

	static double dist(const point &p1, const point &p2) {
		double dx = p1.x - p2.x, dy = p1.y - p2.y, dz = p1.z - p2.z;
		return sqrt(dx * dx + dy * dy + dz * dz);
	}
};

int n;
point all[MAXN], P;
double vp, vs;

point getPoint(double t) {
	double cur = 0.0, last = 0.0;
	int idx = 1;
	while (idx <= n) {
		last = cur;
		cur += point::dist(all[idx], all[idx - 1]) / vs;
		if (cur > t - EPS)
			break;
		idx++;
	}
	if (idx > n)
		idx = n;
	double per = min(t - last, cur - last) / (cur - last);
	point pos = { all[idx - 1].x + per * (all[idx].x - all[idx - 1].x), all[idx
			- 1].y + per * (all[idx].y - all[idx - 1].y), all[idx - 1].z
			+ per * (all[idx].z - all[idx - 1].z) };
	return pos;
}

bool check(double t) {
	point pos = getPoint(t);
	double tt = point::dist(P, pos) / vp;
	return tt < t + EPS;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	scanf("%d", &n);
	for (int i = 0; i <= n; i++)
		scanf("%lf%lf%lf", &all[i].x, &all[i].y, &all[i].z);
	scanf("%lf%lf%lf%lf%lf", &vp, &vs, &P.x, &P.y, &P.z);
	double total = 0.0;
	for (int i = 1; i <= n; i++)
		total += point::dist(all[i], all[i - 1]) / vs;
	double s = 0.0, e = total + 10.0;
	for (double sz = (e - s) / 2.0; sz > EPS; sz /= 2.0)
		if (!check(s + sz))
			s += sz;
	if (s > total + EPS) {
		printf("NO\n");
		return 0;
	}
	point p = getPoint(s);
	printf("YES\n%.6f\n%.6f %.6f %.6f\n", s, p.x, p.y, p.z);
	return 0;
}
