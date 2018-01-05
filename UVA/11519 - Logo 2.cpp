/*
 * 11519 - Logo 2.cpp
 *
 *  Created on: Jan 5, 2018
 *      Author: Osama Hatem
 */
 
/*
Simulate the process and skip the missing instruction. If it is an 'fd' or 'bk'
instruction, then the answer is the distance between the origin and the position
after simulation. Otherwise, let P be the position of the turtle before the
missing instruction, O the origin and F the final position, the answer is the
clockwise angle between vectors PF and PO if the instruction is 'lt', its
complement in case it's 'rt'.
*/

#include <bits/stdtr1c++.h>
#include <ext/numeric>

#define dot(A,B) ((A).x*(B).x+(A).y*(B).y)
#define LENsqr(v)   (dot(v,v))
#define LEN(v)  (sqrtl(LENsqr(v)))
#define VEC(a,b) ((b)-(a))
#define angle(v) (atan2((v).y,(v).x))
#define polar(len,theta) (point(cosl(theta),sinl(theta))*(len))
#define rotate(v,theta) ((v)*polar(1,theta))
#define rad(a) (a*PI/180)
#define deg(a) (a/PI*180)
#define EPS 1e-9

using namespace std;

typedef long double myf;
const myf PI = 4.0L * atan2l(1.0L, 1.0L);

struct point {
	myf x, y;

	point() :
			x(0), y(0) {
	}
	point(myf _x, myf _y) :
			x(_x), y(_y) {
	}

	friend point operator *(const point& A, const point& B) {
		return point(A.x * B.x - A.y * B.y, A.x * B.y + A.y * B.x);
	}

	friend point operator *(const point& A, const myf& sc) {
		return point(A.x * sc, A.y * sc);
	}

	friend point operator +(const point& A, const point& B) {
		return point(A.x + B.x, A.y + B.y);
	}

	friend point operator -(const point& A, const point& B) {
		return point(A.x - B.x, A.y - B.y);
	}
};

int toInt(string &s) {
	int ret = 0;
	for (int i = 0; s[i]; i++)
		ret = ret * 10 + s[i] - '0';
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		point cur(0, 0), p;
		myf ang = 0.0;
		string op, val, miss;
		while (n--) {
			cin >> op >> val;
			if (val == "?") {
				p = cur, miss = op;
			} else {
				if (op == "lt")
					ang += toInt(val);
				else if (op == "rt")
					ang -= toInt(val);
				else if (op == "fd")
					cur = cur + rotate(point(toInt(val), 0), rad(ang));
				else
					cur = cur - rotate(point(toInt(val), 0), rad(ang));
				if (ang > 360)
					ang -= 360;
				if (ang < 0)
					ang += 360;
			}
		}
		if (miss == "fd" || miss == "bk")
			cout << (int) (LEN(VEC(cur, point(0, 0))) + EPS) << endl;
		else {
			myf rot = angle(VEC(p, point(0, 0))) - angle(VEC(p, cur));
			if (rot < 0.0L)
				rot += PI + PI;
			if (miss == "rt")
				rot = PI + PI - rot;
			cout << (int) (deg(rot) + EPS) << endl;
		}
	}
	return 0;
}
