/*
 * 2C. Commentator problem.cpp
 *
 *  Created on: Jan 4, 2018
 *      Author: Osama Hatem
 */
 
/*
http://codeforces.com/blog/entry/109
What the author meant by the angle of observation was not explained in the
problem statement.
*/

#include <bits/stdtr1c++.h>
#include <ext/numeric>

#define LENsqr(v)   (dot(v,v))
#define LEN(v)  (sqrtl(LENsqr(v)))
#define cross(A,B) ((A).x*(B).y-(A).y*(B).x)
#define cross3(a,b,c) cross(VEC(a,b),VEC(a,c))
#define dot(A,B) ((A).x*(B).x+(A).y*(B).y)
#define dot3(a,b,c) dot(VEC(a,b),VEC(a,c))
#define VEC(a,b) ((b)-(a))
#define CCWPerp(v) (point(-(v).y,(v).x))
#define ppDist(A,B) (sqrtl(dot((B)-(A),(B)-(A))))
#define unit(v) ((v)/LEN(v))
#define MID(a,b) (((a)+(b))/2)
#define polar(len,theta) (point(cosl(theta),sinl(theta))*(len))
#define conj(v) point((v).x, -(v).y)
#define rotate(v,theta) ((v)*polar(1,theta))
#define EPS 1e-9
#define OO (1<<30)

using namespace std;

typedef long double myf;

struct point {
	myf x, y;

	point() :
			x(0), y(0) {
	}
	point(myf _x, myf _y) :
			x(_x), y(_y) {
	}

	friend bool operator <(const point& A, const point& B) {
		return A.x < B.x - EPS || (A.x - B.x < EPS && A.y < B.y - EPS);
	}

	friend bool operator ==(const point& A, const point& B) {
		return fabsl(A.x - B.x) < EPS && fabs(A.y - B.y) < EPS;
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

	friend point operator +(const point& A, const myf& sc) {
		return point(A.x + sc, A.y);
	}

	friend point operator -(const point& A, const point& B) {
		return point(A.x - B.x, A.y - B.y);
	}

	friend point operator -(const point& A, const myf& sc) {
		return point(A.x - sc, A.y);
	}

	friend point operator /(const point& A, const point& B) {
		return A * conj(B) / (B.x * B.x + B.y * B.y);
	}

	friend point operator /(const point& A, const myf& sc) {
		return point(A.x / sc, A.y / sc);
	}
};

pair<myf, point> arr[3];

pair<point, int> llIntersect(const point& A0, const point& A1, const point& B0,
		const point& B1) {
	myf s = cross(A0 - B0, A1 - A0) / cross(B1 - B0, A1 - A0);
	return pair<point, int>(B0 + (B1 - B0) * s, isnan(s) + isinf(s) * 2);
	// 1 -> overlapping, 2 -> parallel
}

point plProj(const point& A, const point& B, const point& P) {
	// projection point on line
	myf d = dot3(A, B, P) / ppDist(A, B);
	return unit(VEC(A, B)) * d + A;
}

myf cosRule(myf a, myf b, myf c) {
	// given a,b,c returns C
	// check isTriangle first
	return acosl((a * a + b * b - c * c) / (2 * a * b));
}

int circleCircleIntersection(const point &c1, const myf &r1, const point &c2,
		const myf &r2, point &res1, point &res2) {
	if (c1 == c2 && r1 == r2) {
		res1 = res2 = c1;
		return fabs(r1) < EPS ? 1 : OO;
	}
	myf len = ppDist(c1, c2);
	if (fabs(len - (r1 + r2)) < EPS || fabs(fabs(r1 - r2) - len) < EPS) {
		point d, c;
		myf r;
		if (r1 > r2)
			d = VEC(c1, c2), c = c1, r = r1;
		else
			d = VEC(c2, c1), c = c2, r = r2;
		res1 = res2 = unit(d) * r + c;
		return 1;
	}
	if (len > r1 + r2 || len < fabs(r1 - r2))
		return 0;
	myf a = cosRule(r1, len, r2);
	point c1c2 = unit(VEC(c1,c2)) * r1;
	res1 = rotate(c1c2, a) + c1;
	res2 = rotate(c1c2, -a) + c1;
	return 2;
}

int circleLineIntersection(const point& C, const myf& r, const point& A,
		const point& B, point& res1, point& res2) {
	point P = plProj(A, B, C);
	myf d = ppDist(P, C);
	if (fabsl(d - r) < EPS)
		return res1 = P, 1;
	if (d < EPS) {
		res1 = unit(VEC(A, B)) * r + C;
		res2 = unit(VEC(B, A)) * r + C;
		return 2;
	}
	if (d > r)
		return 0;
	myf theta = acosl(d / r);
	res1 = rotate(unit(VEC(C, P)) * r, theta) + C;
	res2 = rotate(unit(VEC(C, P)) * r, -theta) + C;
	return 2;
}

pair<bool, myf> check(point p) {
	myf ang[3];
	for (int i = 0; i < 3; i++)
		ang[i] = 2.0 * asin(arr[i].first / LEN(VEC(p, arr[i].second)));
	for (int i = 1; i < 3; i++)
		if (abs(ang[i] - ang[0]) > EPS)
			return make_pair(false, 0.0);
	return make_pair(true, ang[0]);
}

void calc(point c1, myf r1, point c2, myf r2, bool &t, point &a, point &b,
		point &c, myf &r) {
	if (abs(r1 - r2) < EPS) {
		t = false;
		a = MID(c1, c2);
		b = a + CCWPerp(VEC(c1, c2));
	} else {
		t = true;
		if (r2 < r1)
			swap(c1, c2), swap(r1, r2);
		point x = c1 + VEC(c1, c2) * r1 / (r1 + r2);
		myf rt = LEN(VEC(c1, c2)) / (r2 - r1);
		point y = c1 + unit(VEC(c2, c1)) * rt * r1;
		c = MID(x, y), r = LEN(VEC(x, y)) / 2.0L;
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cout << fixed << setprecision(5);

	for (int i = 0; i < 3; i++)
		cin >> arr[i].second.x >> arr[i].second.y >> arr[i].first;

	bool t1, t2;
	point a1, b1, c1, a2, b2, c2;
	myf r1, r2;
	calc(arr[0].second, arr[0].first, arr[1].second, arr[1].first, t1, a1, b1,
			c1, r1);
	calc(arr[0].second, arr[0].first, arr[2].second, arr[2].first, t2, a2, b2,
			c2, r2);

	point p1, p2;
	int ret;
	if (t1 && t2)
		ret = circleCircleIntersection(c1, r1, c2, r2, p1, p2);
	else if (t1 && !t2)
		ret = circleLineIntersection(c1, r1, a2, b2, p1, p2);
	else if (!t1 && t2)
		ret = circleLineIntersection(c2, r2, a1, b1, p1, p2);
	else
		ret = 1, p1 = llIntersect(a1, b1, a2, b2).first;

	vector<pair<myf, point>> ans;
	if (ret > 0) {
		auto temp = check(p1);
		if (temp.first)
			ans.push_back(make_pair(temp.second, p1));
	}
	if (ret == 2) {
		auto temp = check(p2);
		if (temp.first)
			ans.push_back(make_pair(temp.second, p2));
	}
	sort(ans.begin(), ans.end());
	if (ans.size())
		cout << ans.back().second.x << " " << ans.back().second.y << endl;
	return 0;
}
