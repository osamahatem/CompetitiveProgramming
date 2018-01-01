/*
 * [gRkn7bDfsN-212807]-D. Arrange the Points!.cpp
 *
 *  Created on: Jan 1, 2018
 *      Author: Osama Hatem
 */
 
/*
Sort the points by their angles relative to any axis. There can be at most one
90+ degrees gap between any 2 consecutive points for the answer to exist, and
this gap is where we should start printing the points.
*/

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const double PI = acos(-1.0);
const double EPS = 1e-9;

struct point {
	int x, y;

	bool operator <(const point &p) const {
		return x < p.x;
	}
};

int n;
pair<double, point> arr[105];

double getAng(point p) {
	double ret = atan2(p.y, p.x);
	if (ret < 0.0)
		ret += 2.0 * PI;
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

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i].second.x >> arr[i].second.y;
		arr[i].first = getAng(arr[i].second);
	}
	sort(arr, arr + n);
	arr[n] = arr[0];
	arr[n].first += 2.0 * PI;
	int cnt = 0, s = 0;
	for (int i = 0; i < n; i++)
		if (arr[i + 1].first - arr[i].first > PI / 2.0 - EPS)
			s = i + 1, cnt++;
	if (cnt < 2)
		for (int j = 0, i = s % n; j < n; j++, i = (i + 1) % n)
			cout << arr[i].second.x << " " << arr[i].second.y << endl;
	else
		cout << "-1" << endl;
	return 0;
}
