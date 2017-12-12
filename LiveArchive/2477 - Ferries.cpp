/*
 * 2477 - Ferries.cpp
 *
 *  Created on: Dec 12, 2017
 *      Author: Osama Hatem
 */

/*
First, we calculate the optimal travel time by simulating driving at maximum
speed, and getting on the ferries as soon as they are available. We can then
use a binary search to determine the minimum maximum speed possible that can
achieve the optimal travel time.
*/

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const double EPS = 1e-9;

int n;
vector<vector<int>> intervals;
char ty[10];

double getFerry(double t, int m, int ft) {
	double ret = m * 60.0;
	while (ret < t)
		ret += 3600.0;
	return ret + ft * 60.0;
}

double check(double sp) {
	double ret = 0.0;
	for (int i = 0; i < n; i++) {
		if (intervals[i].size() == 1)
			ret += intervals[i][0] * 3600.0 / sp;
		else {
			double temp = 1e9;
			for (int j = 0; j < intervals[i][1]; j++)
				temp = min(temp,
						getFerry(ret, intervals[i][2 + j], intervals[i][0]));
			ret = temp;
		}
	}
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int T = 0;
	while (scanf("%d", &n), n) {
		intervals.clear();
		intervals.resize(n);
		for (int i = 0; i < n; i++) {
			intervals.push_back(vector<int>());
			int x;
			scanf("%*s%*s%s%d", ty, &x);
			intervals[i].push_back(x);
			if (ty[0] == 'f') {
				scanf("%d", &x);
				intervals[i].push_back(x);
				for (int j = 0; j < (int) intervals[i][1]; j++) {
					scanf("%d", &x);
					intervals[i].push_back(x);
				}
			}
		}
		double ans = check(80.0);
		double s = 0.0, e = 80.0;
		for (double sz = (e - s) / 2.0; sz > EPS; sz *= 0.5) {
			if (check(s + sz) > ans)
				s += sz;
		}
		int t = (int) (ans + EPS);
		int sec = t % 60;
		t /= 60;
		int m = t % 60;
		t /= 60;
		printf("Test Case %d: %02d:%02d:%02d %.2f\n\n", ++T, t, m, sec, s);
	}
	return 0;
}
