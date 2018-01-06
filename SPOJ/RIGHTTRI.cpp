/*
 * RIGHTTRI.cpp
 *
 *  Created on: Jan 6, 2018
 *      Author: Osama Hatem
 */
 
/*
For each point i, calculate all unit vectors to all other points j, this way all
points having the same direction relative to point i will have the same
representation. Next, sort these vectors and for each, use binary search to
count how many others are perpendicular to it.
*/

#include <bits/stdtr1c++.h>
#include <ext/numeric>

#define LENsqr(v)   (dot(v,v))
#define LEN(v)  (sqrtl(LENsqr(v)))
#define dot(A,B) ((A).x*(B).x+(A).y*(B).y)
#define VEC(a,b) ((b)-(a))
#define CWPerp(v) (point((v).y,-(v).x))
#define unit(v) ((v)/LEN(v))
#define EPS 1e-15

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

	friend point operator -(const point& A, const point& B) {
		return point(A.x - B.x, A.y - B.y);
	}

	friend point operator /(const point& A, const myf& sc) {
		return point(A.x / sc, A.y / sc);
	}
};

int n;
point arr[1505];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i].x >> arr[i].y;

	int ans = 0;
	for (int i = 0; i < n; i++) {
		vector<point> vecs;
		for (int j = 0; j < n; j++)
			if (i != j)
				vecs.push_back(unit(VEC(arr[i], arr[j])));
		sort(vecs.begin(), vecs.end());
		for (int j = 0; j + 1 < n; j++) {
			point p = CWPerp(vecs[j]);
			ans += upper_bound(vecs.begin(), vecs.end(), p)
					- lower_bound(vecs.begin(), vecs.end(), p);
		}
	}
	cout << ans << endl;
	return 0;
}
