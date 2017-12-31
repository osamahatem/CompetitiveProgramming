/*
 * 10005 - Packing polygons.cpp
 *
 *  Created on: Dec 31, 2017
 *      Author: Osama Hatem
 */
 
/*
Get smallest radius of a circle covering all given points and compare it to R.
This is done by trying all circles passing by 2 or 3 points, and picking the
smallest. O(N^4).
*/

#include <bits/stdtr1c++.h>
#include <ext/numeric>

#define LENsqr(v)   (dot(v,v))
#define LEN(v)  (sqrtl(LENsqr(v)))
#define dot(A,B) ((A).x*(B).x+(A).y*(B).y)
#define VEC(a,b) ((b)-(a))
#define cross(A,B) ((A).x*(B).y-(A).y*(B).x)
#define CCWPerp(v) (point(-(v).y,(v).x))
#define MID(a,b) (((a)+(b))/2)
#define mk make_pair
#define fi first
#define se second

using namespace std;

typedef long double myf;

const double EPS = 1e-9;

struct point {
	myf x, y;

	point() :
			x(0), y(0) {
	}
	point(myf _x, myf _y) :
			x(_x), y(_y) {
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

	friend point operator /(const point& A, const myf& sc) {
		return point(A.x / sc, A.y / sc);
	}
};

point arr[105];
int n;
myf R;

point perp(const point& A, const point& B, const point& P) {
	return CCWPerp(VEC(A, B)) + P;
}

pair<point, int> llIntersect(const point& A0, const point& A1, const point& B0,
		const point& B1) {
	myf s = cross(A0 - B0, A1 - A0) / cross(B1 - B0, A1 - A0);
	return pair<point, int>(B0 + (B1 - B0) * s, isnan(s) + isinf(s) * 2);
}

point circle3(const point& A, const point& B, const point& C) {
	return llIntersect(MID(A, B), perp(A, B, MID(A, B)), MID(B, C),
			perp(B, C, MID(B, C))).fi;
}

point circle2(const point& A, const point& B) {
	return MID(A, B);
}

bool pointInCircle(const point& C, myf r, const point& P) {
	myf d = LENsqr(VEC(C, P));
	return d < r * r + EPS;
}

myf check(point C) {
	myf ret = 0.0;
	for (int i = 0; i < n; i++)
		ret = max(ret, LEN(VEC(C, arr[i])));
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

	while (cin >> n, n) {
		myf rr = 1e9;
		for (int i = 0; i < n; i++)
			cin >> arr[i].x >> arr[i].y;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < i; j++) {
				rr = min(rr, check(circle2(arr[i], arr[j])));
				for (int k = j + 1; k < i; k++)
					rr = min(rr, check(circle3(arr[i], arr[j], arr[k])));
			}
		}
		cin >> R;
		if (R > rr - EPS)
			cout << "The polygon can be packed in the circle." << endl;
		else
			cout << "There is no way of packing that polygon." << endl;
	}
	return 0;
}
