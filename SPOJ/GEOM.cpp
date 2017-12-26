/*
 * GEOM.cpp
 *
 *  Created on: Dec 14, 2017
 *      Author: Osama Hatem
 */
 
/*
Get an intersection point and check that it lies on all four lines.
*/

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const double EPS = 1e-9;

struct point {
	double x, y;

	static double cross(const point &p1, const point &p2) {
		return p1.x * p2.y - p1.y * p2.x;
	}

	static point toVec(const point &p1, const point &p2) {
		return point { p2.x - p1.x, p2.y - p1.y };
	}

	static pair<point, int> inter(point a0, point a1, point b0, point b1) {
		point ba = toVec(b0, a0), aa = toVec(a0, a1), bb = toVec(b0, b1);
		double s = cross(ba, aa) / cross(bb, aa);
		return make_pair(point { bb.x * s + b0.x, bb.y * s + b0.y },
				isnan(s) + isinf(s) * 2);
	}
};

bool pointOnLine(point &a, point &b, point &c) {
	return point::cross(point::toVec(a, b), point::toVec(a, c)) < EPS;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	double xc, yc, s;
	cin >> xc >> yc >> s;
	point all[] = { { xc - s / 2.0, yc - s / 2.0 },
			{ xc - s / 2.0, yc + s / 2.0 }, { xc + s / 2.0, yc + s / 2.0 }, { xc
					+ s / 2.0, yc - s / 2.0 } };
	point P;
	cin >> P.x >> P.y;

	point vecs[4];
	for (int i = 0; i < 4; i++)
		vecs[i] = point::toVec(all[i], P);

	pair<point, point> lines[4];
	for (int i = 0; i < 4; i++) {
		point v = vecs[(i + 1) % 4];
		lines[i] = make_pair(all[i], point { all[i].x - v.y, all[i].y + v.x });
	}

	bool valid = false;
	point in;
	for (int i = 0; i < 4; i++) {
		for (int j = i + 1; j < 4; j++) {
			pair<point, int> r = point::inter(lines[i].first, lines[i].second,
					lines[j].first, lines[j].second);
			if (r.second == 0)
				valid = true, in = r.first;
		}
	}
	if (!valid) {
		cout << "NO" << endl;
		return 0;
	}
	valid = true;
	for (int i = 0; i < 4; i++)
		if (!pointOnLine(lines[i].first, lines[i].second, in))
			valid = false;
	if (!valid) {
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	cout << fixed << setprecision(1) << in.x << " " << in.y << endl;
	return 0;
}
