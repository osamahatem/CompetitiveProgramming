/*
 * sherlock-and-geometry.cpp
 *
 *  Created on: Dec 13, 2017
 *      Author: Osama Hatem
 */
 
/*
For each side of the triangle, get the minimum and maximum distance to the centre
of the circle, and check if the radius is between these 2 distances.
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

	static double dot(const point &p1, const point &p2) {
		return p1.x * p2.x + p1.y * p2.y;
	}

	static double dist(const point &p1, const point &p2) {
		double dx = p2.x - p1.x, dy = p2.y - p1.y;
		return sqrt(dx * dx + dy * dy);
	}

	double len() const {
		return sqrt(x * x + y * y);
	}
};

point c, tr[3];
double r;

bool check(point p1, point p2) {
	double d1 = point::dist(p1, c), d2 = point::dist(p2, c);
	double maxDist = max(d1, d2), minDist = min(d1, d2);
	point v_ab = { p2.x - p1.x, p2.y - p1.y };
	point v_ba = { -v_ab.x, -v_ab.y };
	point v_ac = { c.x - p1.x, c.y - p1.y };
	point v_bc = { c.x - p2.x, c.y - p2.y };
	double perp = abs(point::cross(v_ab, v_ac) / v_ab.len());
	if (point::dot(v_ab, v_ac) > -EPS && point::dot(v_ba, v_bc) > -EPS)
		minDist = min(minDist, perp);
	return minDist < r + EPS && maxDist > r - EPS;
}

int main() {
#ifndef ONLINE_JUDGE
//	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--) {
		bool ans = false;
		cin >> c.x >> c.y >> r;
		for (int i = 0; i < 3; i++) {
			cin >> tr[i].x >> tr[i].y;
			for (int j = 0; j < i; j++)
				ans |= check(tr[i], tr[j]);
		}
		cout << (ans ? "YES" : "NO") << endl;
	}
	return 0;
}
