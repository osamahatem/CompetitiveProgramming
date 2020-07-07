/*
 * 11176 - Winning Streak.cpp
 *
 *  Created on: Dec 6, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

bool vis[505][2][2];
double dp[505][2][2], p;
int w;

double solve(int n, bool flag, bool last) {
	if (n == 0)
		return flag ? 1.0 : 0.0;
	if (vis[n][flag][last])
		return dp[n][flag][last];
	vis[n][flag][last] = 1;
	double ret = (1.0 - p) * solve(n - 1, flag, 0);
	double temp = 1.0;
	for (int i = 1; !last && i <= w && i <= n; i++) {
		temp *= p;
		ret += temp * solve(n - i, flag || i == w, 1);
	}
	return dp[n][flag][last] = ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n;
	while (scanf("%d%lf", &n, &p), n) {
		double ans = 0.0;
		for (int i = 1; i <= n; i++) {
			memset(vis, 0, sizeof vis);
			w = i;
			ans += solve(n, 0, 0) * i;
		}
		printf("%.6f\n", ans);
	}
	return 0;
}
