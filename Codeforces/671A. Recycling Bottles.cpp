/*
 * 671A. Recycling Bottles.cpp
 *
 *  Created on: May 11, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int ax, ay, bx, by, tx, ty, n;
vector<pair<int, int>> all;
double dp[100005][2][2];
bool vis[100005][2][2];

double dist(int x1, int y1, int x2, int y2) {
	int dx = x1 - x2, dy = y1 - y2;
	return sqrt(1ll * dx * dx + 1ll * dy * dy);
}

double solve(int idx, bool a, bool b) {
	if (idx == n)
		return 0.0;
	if (vis[idx][a][b])
		return dp[idx][a][b];
	vis[idx][a][b] = 1;
	double &ret = dp[idx][a][b];
	ret = -1e18;
	double da = dist(ax, ay, all[idx].first, all[idx].second);
	double db = dist(bx, by, all[idx].first, all[idx].second);
	double dt = dist(tx, ty, all[idx].first, all[idx].second);
	if (!a)
		ret = max(ret, solve(idx + 1, 1, b) + dt - da);
	if (!b)
		ret = max(ret, solve(idx + 1, a, 1) + dt - db);
	if (a || b || idx < n - 1)
		ret = max(ret, solve(idx + 1, a, b));
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	scanf("%d%d%d%d%d%d%d", &ax, &ay, &bx, &by, &tx, &ty, &n);
	all.resize(n);
	double ans = 0.0;
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &all[i].first, &all[i].second);
		ans += 2.0 * dist(all[i].first, all[i].second, tx, ty);
	}
	ans -= solve(0, 0, 0);
	printf("%.6f\n", ans);
	return 0;
}
