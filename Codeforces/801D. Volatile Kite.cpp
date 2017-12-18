/*
 * 801D. Volatile Kite.cpp
 *
 *  Created on: Dec 18, 2017
 *      Author: Osama Hatem
 */
 
/*
We want the minimum distance needed to make any angle of the polygon concave. To
calculate it, we check every 3 consecutive points, let them be called a, b, and
c, and calculate the minimum distance to convert the angle formed by these 3
points: this is the distance between point b and segment ac, divided by 2
because we can move point b half that distance in one direction, and points a
and c half the distance in the other direction.
*/

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const double EPS = 1e-9;

struct point {
	double x, y;

	double len() {
		return sqrt(x * x + y * y);
	}

	static double cross(const point &p1, const point &p2) {
		return p1.x * p2.y - p1.y * p2.x;
	}

	static point toVec(const point &p1, const point &p2) {
		return point { p2.x - p1.x, p2.y - p1.y };
	}
};

int n;
point all[1010];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> all[i].x >> all[i].y;

	double ans = 1e18;
	for (int i = 0; i < n; i++) {
		point a = all[i], b = all[(i + 2) % n], c = all[(i + 1) % n];
		point v1 = point::toVec(a, b), v2 = point::toVec(a, c);
		ans = min(ans, point::cross(v1, v2) / (2.0 * v1.len()));
	}
	cout << fixed << setprecision(6) << ans + EPS << endl;
	return 0;
}
