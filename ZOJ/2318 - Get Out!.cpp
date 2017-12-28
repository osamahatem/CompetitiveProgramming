/*
 * 2318 - Get Out!.cpp
 *
 *  Created on: Dec 26, 2017
 *      Author: Osama Hatem
 */
 
/*
First, we add the radius of the boat to all the islands, and the boat can be
simply considered a point. We also draw a line between the centres of any two
circles if they strictly intersect. Now the problem becomes whether the point
representing the boat is enclosed within a polygon formed by those lines.
We do not need to consider intersections between those lines other than at the
circle centres, because if two lines intersect, it means the four circles
forming them do intersect, and there will be extra lines which will form an
enclosed polygon anyway.
To check we perform a dfs that keeps track of the angle difference traversed
since the start node, relative to the centre of the boat. If we reach a
previously visited node after going around a full circle, we cannot escape.
*/

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const double EPS = 1e-6;
const double PI = acos(-1.0);

struct point {
	double x, y;
};

point isl_c[305], boat_c;
double isl_r[305], boat_r;
int n;
bool vis[305];
double last[305];

bool intersect(point c1, double r1, point c2, double r2) {
	double dist = hypot(c1.x - c2.x, c1.y - c2.y);
	return dist < r1 + r2 - EPS && dist > abs(r1 - r2) + EPS;
}

double get_range(point p1, point p2) {
	double a1 = atan2(p1.y - boat_c.y, p1.x - boat_c.x);
	double a2 = atan2(p2.y - boat_c.y, p2.x - boat_c.x);
	if (a1 < a2 - EPS && a2 - a1 > PI + EPS)
		a1 += 2.0 * PI;
	else if (a2 < a1 - EPS && a1 - a2 > PI + EPS)
		a2 += 2.0 * PI;
	return a2 - a1;
}

bool dfs(int idx, int par, double ang) {
	if (vis[idx])
		return (abs(ang - last[idx]) > 2.0 * PI - EPS ? false : true);
	vis[idx] = 1, last[idx] = ang;
	for (int i = 0; i < n; i++) {
		if (i == idx || i == par)
			continue;
		if (intersect(isl_c[idx], isl_r[idx], isl_c[i], isl_r[i])) {
			double temp = get_range(isl_c[idx], isl_c[i]);
			if (!dfs(i, idx, ang + temp))
				return false;
		}
	}
	return true;
}

int main() {
//#ifndef ONLINE_JUDGE
//	freopen("in.in", "r", stdin);
////	freopen("out.out", "w", stdout);
//#endif

	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;
	while (T--) {
		memset(vis, 0, sizeof vis);
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> isl_c[i].x >> isl_c[i].y >> isl_r[i];
		cin >> boat_c.x >> boat_c.y >> boat_r;
		for (int i = 0; i < n; i++)
			isl_r[i] += boat_r;
		bool ans = true;
		for (int i = 0; i < n; i++) {
			if (vis[i])
				continue;
			ans &= dfs(i, -1, 0.0);
		}
		cout << (ans ? "YES" : "NO") << endl;
		if (T)
			cout << endl;
	}
	return 0;
}
