/*
 * 2377 - Grand Prix.cpp
 *
 *  Created on: Jan 23, 2018
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

#define vec(a, b) ((b) - (a))
#define angle(v) (atan2l((v).y, (v).x))
#define deg(a) (a / PI * 180.0L)

using namespace std;

typedef long double myf;
const myf PI = acosl(-1.0L);
const myf EPS = 1e-9;

struct point {
	myf x, y;

	point() :
			x(0), y(0) {
	}
	point(myf _x, myf _y) :
			x(_x), y(_y) {
	}

	friend point operator -(const point& A, const point& B) {
		return point(A.x - B.x, A.y - B.y);
	}
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(2);

	int n, deg, T = 0;
	while (cin >> n >> deg, n) {
		point last(0, 0), cur;
		myf mx_cw = PI, mn_cw = 0.0L, mx_ccw = PI, mn_ccw = 0.0L;
		for (int i = 0; i < n; i++) {
			cin >> cur.x >> cur.y;
			point v = vec(last, cur);
			myf ang = angle(v);
			if (abs(ang) < PI / 2.0L + EPS) {
				mx_cw = min(mx_cw, PI / 2.0L + ang);
				mx_ccw = min(mx_ccw, PI / 2.0L - ang);
			} else {
				myf t_ang = ang < -EPS ? ang + PI + PI : ang;
				mn_cw = max(mn_cw, t_ang - PI / 2.0L);
				mn_ccw = max(mn_ccw, 3.0L * PI / 2.0L - t_ang);
			}
			last = cur;
		}
		myf ans_cw = mx_cw > mn_cw - EPS ? mn_cw : PI + PI;
		myf ans_ccw = mx_ccw > mn_ccw - EPS ? mn_ccw : PI + PI;
		cout << "Case " << ++T << ": ";
		if (deg == 0 || min(ans_cw, ans_ccw) < EPS)
			cout << "Acceptable as proposed";
		else if (min(ans_cw, ans_ccw) > PI + EPS)
			cout << "Unacceptable";
		else if (ans_cw < ans_ccw + EPS)
			cout << "Acceptable after clockwise rotation of " << deg(ans_cw)
					<< " degrees";
		else
			cout << "Acceptable after counterclockwise rotation of "
					<< deg(ans_ccw) << " degrees";
		cout << endl << endl;
	}
	return 0;
}
