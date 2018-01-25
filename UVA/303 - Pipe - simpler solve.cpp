/*
 * 303 - Pipe - simpler solve.cpp
 *
 *  Created on: Jan 25, 2018
 *      Author: Osama Hatem
 */
 
/*
The line providing the best answer must pass through 2 vertices of the pipe. If
a line doesn't, it can always be moved to satisfy that condition, while yielding
an answer that is at least as good.
Given this info, we try all lines formed by all pairs of vertices, and for each
we calculate the earliest point at which it exits the pipe. The answer is the
largest x-coordinates of these points.
Complexity O(N^3).
*/

#include <bits/stdtr1c++.h>
#include <ext/numeric>

#define cross(A,B) ((A).x*(B).y-(A).y*(B).x)
#define cross3(a,b,c) cross(VEC(a,b),VEC(a,c))
#define VEC(a,b) ((b)-(a))

using namespace std;

typedef long double myf;

const myf EPS = 1e-9;

struct point {
	myf x, y;

	point() :
			x(0), y(0) {
	}
	point(myf _x, myf _y) :
			x(_x), y(_y) {
	}

	friend point operator +(const point& A, const point& B) {
		return point(A.x + B.x, A.y + B.y);
	}

	friend point operator -(const point& A, const point& B) {
		return point(A.x - B.x, A.y - B.y);
	}

	friend point operator *(const point& A, const myf& sc) {
		return point(A.x * sc, A.y * sc);
	}
};

int n;
point all[22];

pair<point, int> llIntersect(point A0, point A1, point B0, point B1) {
	myf s = cross(A0 - B0, A1 - A0) / cross(B1 - B0, A1 - A0);
	return pair<point, int>(B0 + (B1 - B0) * s, isnan(s) + isinf(s) * 2);
}

myf solve(point a, point b) {
	if (cross3(a, b, all[0]) < -EPS
			|| cross3(a, b, point(all[0].x, all[0].y - 1)) > EPS)
		return all[0].x;
	for (int i = 1; i < n; i++) {
		if (cross3(a, b, all[i]) < -EPS)
			return llIntersect(a, b, all[i - 1], all[i]).first.x;
		if (cross3(a, b, point(all[i].x, all[i].y - 1)) > EPS)
			return llIntersect(a, b, point(all[i - 1].x, all[i - 1].y - 1),
					point(all[i].x, all[i].y - 1)).first.x;
	}
	return all[n - 1].x;
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

	while (cin >> n, n) {
		for (int i = 0; i < n; i++)
			cin >> all[i].x >> all[i].y;

		myf ans = all[0].x;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				ans = max(ans, solve(all[i], all[j]));
				ans = max(ans, solve(all[i], point(all[j].x, all[j].y - 1)));
				ans = max(ans, solve(point(all[i].x, all[i].y - 1), all[j]));
				ans = max(ans,
						solve(point(all[i].x, all[i].y - 1),
								point(all[j].x, all[j].y - 1)));
			}
		}
		if (abs(ans - all[n - 1].x) < EPS)
			cout << "Through all the pipe." << endl;
		else
			cout << ans << endl;
	}
	return 0;
}
