/*
 * house-location.cpp
 *
 *  Created on: Feb 9, 2018
 *      Author: Osama Hatem
 */
 
/*
Let's consider the first 2 homes, and let them be situated at points h1 and h2,
respectively. Assume we know the distance d1 the new home will be from h2, all
possible placements form a circle of radius d1 centred at h2. Now we know the
distance needed from h1, which is a * d1, and this forms another circle of
radius a * d1 centred at h1. Their intersection represents the points satisfying
the requirement in the problem statement for these 2 houses at d = d1.
If we observe these 2 circles at different values of d, we will find that the
union of their intersections for all values of d is another circle that can be
easily computed. We can compute a similar circle for houses 3 and 4, and the
intersections of these 2 circles are all the valid placements for the new house.
*/

#include <bits/stdtr1c++.h>
#include <ext/numeric>

#define LENsqr(v)   (dot(v,v))
#define LEN(v)  (sqrtl(LENsqr(v)))
#define dot(A,B) ((A).x*(B).x+(A).y*(B).y)
#define VEC(a,b) ((b)-(a))
#define unit(v) ((v)/LEN(v))
#define MID(a,b) (((a)+(b))/2)
#define ppDist(A,B) (LEN(VEC(A,B)))
#define polar(len,theta) (point(cosl(theta),sinl(theta))*(len))
#define rotate(v,theta) ((v)*polar(1,theta))

using namespace std;

typedef long double myf;

const myf PI = acosl(-1.0L);
const myf EPS = 1e-9;
const int OO = 1 << 30;

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

	friend point operator -(const point& A, const point& B) {
		return point(A.x - B.x, A.y - B.y);
	}

	friend point operator /(const point& A, const myf& sc) {
		return point(A.x / sc, A.y / sc);
	}
};

myf cosRule(myf a, myf b, myf c) {
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
	point c1c2 = unit(VEC(c1, c2)) * r1;
	res1 = rotate(c1c2, a) + c1;
	res2 = rotate(c1c2, -a) + c1;
	return 2;
}

point h1, h2, h3, h4;
myf rat1, rat2;

pair<point, myf> getCircle(point c1, point c2, myf rat) {
	if (h1 == h2)
		return make_pair(c1, 0.0L);

	point v = VEC(c1, c2);
	point u = unit(v);
	myf len = LEN(v);

	point p1 = u * (len / (rat + 1.0L)) + c1;
	point p2 = c1 - u * (len / (rat - 1.0L));
	point c = MID(p1, p2);
	return make_pair(c, LEN(VEC(c, p1)));
}

int main() {
//#ifndef ONLINE_JUDGE
//	freopen("in.in", "r", stdin);
////	freopen("out.out", "w", stdout);
//#endif

	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(2);

	cin >> rat1 >> rat2;
	cin >> h1.x >> h1.y >> h2.x >> h2.y;
	cin >> h3.x >> h3.y >> h4.x >> h4.y;

	auto cir1 = getCircle(h2, h1, rat1);
	auto cir2 = getCircle(h4, h3, rat2);
	point res1, res2, ans;
	int cnt = circleCircleIntersection(cir1.first, cir1.second, cir2.first,
			cir2.second, res1, res2);
	if (cnt == 0) {
		cout << "Impossible!" << endl;
		return 0;
	}
	if (cnt == OO)
		ans = point(cir1.first.x - cir1.second, cir2.first.y);
	else {
		ans = res1;
		if (cnt == 2)
			ans = min(ans, res2);
	}
	cout << ans.x << " " << ans.y << endl;
	return 0;
}
