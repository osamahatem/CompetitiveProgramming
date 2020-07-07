/*
 * 474C. Captain Marmot.cpp
 *
 *  Created on: Jul 11, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

struct point {
	int x, y;

	bool operator ==(const point &p) {
		return x == p.x && y == p.y;
	}
};

int distSq(point p1, point p2) {
	return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

bool isSquare(point p1, point p2, point p3, point p4) {
	if (p1 == p2 || p1 == p3 || p1 == p4 || p2 == p3 || p2 == p4 || p3 == p4)
		return false;
	int d2 = distSq(p1, p2);
	int d3 = distSq(p1, p3);
	int d4 = distSq(p1, p4);
	if (d2 == d3 && 2 * d2 == d4) {
		int d = distSq(p2, p4);
		return (d == distSq(p3, p4) && d == d2);
	}
	if (d3 == d4 && 2 * d3 == d2) {
		int d = distSq(p2, p3);
		return (d == distSq(p2, p4) && d == d3);
	}
	if (d2 == d4 && 2 * d2 == d3) {
		int d = distSq(p2, p3);
		return (d == distSq(p3, p4) && d == d2);
	}
	return false;
}

point rotate90(point p) {
	point ret = p;
	ret.y *= -1;
	swap(ret.x, ret.y);
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n;
	point pts[4], org[4];
	cin >> n;
	while (n--) {
		for (int i = 0; i < 4; i++)
			cin >> pts[i].x >> pts[i].y >> org[i].x >> org[i].y;
		int mini = 1000;
		for (int a = 0; a < 4; a++) {
			for (int b = 0; b < 4; b++) {
				for (int c = 0; c < 4; c++) {
					for (int d = 0; d < 4; d++) {
						if (isSquare(pts[0], pts[1], pts[2], pts[3]))
							mini = min(mini, a + b + c + d);
						pts[3].x -= org[3].x, pts[3].y -= org[3].y;
						pts[3] = rotate90(pts[3]);
						pts[3].x += org[3].x, pts[3].y += org[3].y;
					}
					pts[2].x -= org[2].x, pts[2].y -= org[2].y;
					pts[2] = rotate90(pts[2]);
					pts[2].x += org[2].x, pts[2].y += org[2].y;
				}
				pts[1].x -= org[1].x, pts[1].y -= org[1].y;
				pts[1] = rotate90(pts[1]);
				pts[1].x += org[1].x, pts[1].y += org[1].y;
			}
			pts[0].x -= org[0].x, pts[0].y -= org[0].y;
			pts[0] = rotate90(pts[0]);
			pts[0].x += org[0].x, pts[0].y += org[0].y;
		}
		cout << (mini == 1000 ? -1 : mini) << endl;
	}
	return 0;
}
