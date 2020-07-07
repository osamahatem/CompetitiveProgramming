/*
 * 552D. Vanya and Triangles.cpp
 *
 *  Created on: Jun 18, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

vector<pair<int, int>> points;
vector<pair<int, int>> slopes[2005];

pair<int, int> getSlope(pair<int, int> p1, pair<int, int> p2) {
	int x1 = p1.first, x2 = p2.first, y1 = p1.second, y2 = p2.second;
	int dx = x2 - x1, dy = y2 - y1;
	if (!dx)
		return make_pair(1, 0);
	if (!dy)
		return make_pair(0, 1);
	int g = __gcd(abs(dx), abs(dy));
	dx /= g, dy /= g;
	if (dy < 0)
		dx *= -1, dy *= -1;
	return make_pair(dx, dy);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n;
	cin >> n;
	points.resize(n);
	for (int i = 0; i < n; i++)
		cin >> points[i].first >> points[i].second;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++)
			slopes[i].push_back(getSlope(points[i], points[j]));
		sort(slopes[i].begin(), slopes[i].end());
	}
	long long ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++) {
			pair<int, int> curSlope = getSlope(points[i], points[j]);
			int lb = lower_bound(slopes[i].begin(), slopes[i].end(), curSlope)
					- slopes[i].begin();
			int ub = upper_bound(slopes[i].begin(), slopes[i].end(), curSlope)
					- slopes[i].begin();
			ans += (int) slopes[i].size() - ub + lb;
		}
	cout << ans / 2 << endl;
	return 0;
}
