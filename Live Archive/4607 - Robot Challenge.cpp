/*
 * 4607 - Robot Challenge.cpp
 *
 *  Created on: Oct 3, 2014
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

bool vis[1005];
double dp[1005];
vector<pair<pair<int, int>, int> > all;
int n;

double dist(int x1, int x2, int y1, int y2) {
	int dx = x2 - x1;
	int dy = y2 - y1;
	return sqrt(dx * dx + dy * dy);
}

double solve(int idx) {
	if (idx == n + 1)
		return 0.0;
	if (vis[idx])
		return dp[idx];
	vis[idx] = 1;
	int p = 0;
	for (int i = idx + 1; i <= n + 1; i++) {
		double d = dist(all[i].first.first, all[idx].first.first,
				all[i].first.second, all[idx].first.second);
		dp[idx] = min(dp[idx], 1.0 + p + d + solve(i));
		p += all[i].second;
	}
	return dp[idx];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	while (cin >> n, n) {
		for (int i = 0; i <= n + 1; i++)
			vis[i] = 0, dp[i] = 1e9;
		all.clear();
		all.push_back(make_pair(make_pair(0, 0), 0));
		int x, y, p;
		for (int i = 0; i < n; i++) {
			cin >> x >> y >> p;
			all.push_back(make_pair(make_pair(x, y), p));
		}
		all.push_back(make_pair(make_pair(100, 100), p));
		printf("%.3f\n", solve(0));
	}
	return 0;
}
