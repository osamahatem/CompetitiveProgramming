/*
 * L. L-Shapes.cpp
 *
 *  Created on: Oct 3, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

struct point {
	int x, y;

	point(int _x, int _y) {
		x = _x, y = _y;
	}

	const bool operator ==(const point &rhs) const {
		return rhs.x == x && rhs.y == y;
	}

	point operator -(const point &rhs) const {
		return point(rhs.x - x, rhs.y - y);
	}
};

vector<pair<point, point>> all;
int n;

int dot(point p1, point p2) {
	return p1.x * p2.x + p1.y * p2.y;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	freopen("lshape.in", "r", stdin);
	freopen("lshape.out", "w", stdout);
	scanf("%d", &n);
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int x1, y1, x2, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		all.push_back(make_pair(point(x1, y1), point(x2, y2)));
		for (int j = 0; j < i; j++) {
			if (all[j].first == all[i].first || all[j].first == all[i].second
					|| all[j].second == all[i].first
					|| all[j].second == all[i].second)
				ans += dot(all[j].second - all[j].first,
						all[i].second - all[i].first) == 0;
		}
	}
	printf("%d\n", ans);
	return 0;
}
