/*
 * 11473 - Campus Roads.cpp
 *
 *  Created on: Dec 31, 2017
 *      Author: Osama Hatem
 */
 
/*
The fixed distance can be easily calculated. Start at the first point and move
on the segments with this distance every step.
*/

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const double EPS = 1e-9;

struct point {
	double x, y;
};

point arr[105];

double dist(point p1, point p2) {
	return hypot(p1.x - p2.x, p1.y - p2.y);
}

point getPointOnLine(point a, point b, double d) {
	double p = d / dist(a, b);
	return point { a.x + p * (b.x - a.x), a.y + p * (b.y - a.y) };
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cout << fixed << setprecision(2);

	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cout << "Road #" << t << ":" << endl;
		int n, c;
		cin >> n >> c;
		for (int i = 0; i < n; i++)
			cin >> arr[i].x >> arr[i].y;
		double tot = 0.0;
		for (int i = 1; i < n; i++)
			tot += dist(arr[i - 1], arr[i]);
		double d = tot / (c - 1);
		double cur = 0.0;
		for (int i = 1; i < n; i++) {
			double temp = dist(arr[i - 1], arr[i]);
			while (cur < temp + EPS) {
				point p = getPointOnLine(arr[i - 1], arr[i], cur);
				cout << p.x << " " << p.y << endl;
				cur += d;
			}
			cur -= temp;
		}
		cout << endl;
	}
	return 0;
}
