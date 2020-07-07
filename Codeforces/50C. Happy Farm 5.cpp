/*
 * 50C. Happy Farm 5.cpp
 *
 *  Created on: Aug 17, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

struct point {
	int x, y;

	const bool operator ==(const point &p) const {
		return x == p.x && y == p.y;
	}
} P;

long long ccw(const point &p1, const point &p2, const point &p3) {
	return (long long) (p2.x - p1.x) * (p3.y - p1.y)
			- (long long) (p2.y - p1.y) * (p3.x - p1.x);
}

long long distSq(const point &p1, const point &p2) {
	return (long long) (p1.x - p2.x) * (p1.x - p2.x)
			+ (long long) (p1.y - p2.y) * (p1.y - p2.y);
}

bool ccw_cmp(const point &p1, const point &p2) {
	long long c = ccw(P, p1, p2);
	return (c != 0 ? c > 0 : distSq(P, p1) < distSq(P, p2));
}

vector<point> convexHull(vector<point> all) {
	P = all[0];
	for (int i = 1; i < (int) all.size(); i++)
		if ((all[i].y < P.y) || (all[i].y == P.y && all[i].x < P.x))
			P = all[i];
	sort(all.begin(), all.end(), ccw_cmp);
	all.erase(unique(all.begin(), all.end()), all.end());
	vector<point> ans;
	int sz = 0;
	for (int i = 0; i < (int) all.size(); i++) {
		if (sz > 2 && ccw(ans[sz - 2], ans[sz - 1], all[i]) < 0) {
			sz--, i--;
			ans.pop_back();
		} else {
			ans.push_back(all[i]);
			sz++;
		}
	}
	return ans;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n;
	cin >> n;
	vector<point> all(n);
	for (int i = 0; i < n; i++)
		cin >> all[i].x >> all[i].y;
	vector<point> ch = convexHull(all);
	ch.push_back(ch[0]);
	long long ans = 4;
	for (int i = 1; i < (int) ch.size(); i++)
		ans += max(abs(ch[i].x - ch[i - 1].x), abs(ch[i].y - ch[i - 1].y));
	cout << ans << endl;
	return 0;
}
