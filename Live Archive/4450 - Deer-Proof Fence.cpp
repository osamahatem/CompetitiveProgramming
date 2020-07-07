/*
 * 4450 - Deer-Proof Fence.cpp
 *
 *  Created on: Feb 2, 2018
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

#define LENsqr(v)   (dot(v,v))
#define LEN(v)  (sqrtl(LENsqr(v)))
#define dot(A,B) ((A).x*(B).x+(A).y*(B).y)
#define cross(A,B) ((A).x*(B).y-(A).y*(B).x)
#define VEC(a,b) ((b)-(a))

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

	friend bool operator <(const point& A, const point& B) {
		return A.x < B.x - EPS || (A.x - B.x < EPS && A.y < B.y - EPS);
	}

	friend point operator -(const point& A, const point& B) {
		return point(A.x - B.x, A.y - B.y);
	}
};

int n, r;
point p[10];
bool vis[1 << 9];
myf dp[1 << 9];

myf CHP(vector<point> P) {
	int sz = P.size(), k = 0;
	vector<point> H(2 * sz);
	for (int i = 0; i < sz; ++i) {
		while (k >= 2
				&& cross(VEC(H[k - 2], H[k - 1]), VEC(H[k - 2], P[i])) < EPS)
			--k;
		H[k++] = P[i];
	}
	for (int i = sz - 2, t = k + 1; i >= 0; --i) {
		while (k >= t
				&& cross(VEC(H[k - 2], H[k - 1]), VEC(H[k - 2], P[i])) < EPS)
			--k;
		H[k++] = P[i];
	}
	myf ret = 0.0L;
	for (int i = 1; i < k; i++)
		ret += LEN(VEC(H[i - 1], H[i]));
	ret += LEN(VEC(H[k - 1], H[0]));
	return ret;
}

myf solve(int mask) {
	if (!mask)
		return 0.0L;
	if (vis[mask])
		return dp[mask];
	vis[mask] = true;
	myf &ret = dp[mask];
	ret = 1e9;
	for (int m = mask; m; m = (m - 1) & mask) {
		vector<point> temp;
		for (int i = 0; i < n; i++)
			if (m & (1 << i))
				temp.push_back(p[i]);
		ret = min(ret, CHP(temp) + 2.0L * PI * r + solve(mask ^ m));
	}
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

	cout << fixed << setprecision(2);

	int T = 0;
	while (cin >> n >> r, n) {
		memset(vis, 0, sizeof vis);
		for (int i = 0; i < n; i++)
			cin >> p[i].x >> p[i].y;
		sort(p, p + n);
		cout << "Case " << ++T << ": length = " << solve((1 << n) - 1) << endl;
	}
	return 0;
}
