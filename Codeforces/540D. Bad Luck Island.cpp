/*
 * 540D. Bad Luck Island.cpp
 *
 *  Created on: Apr 30, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

bool vis[105][105][105];
double dp[105][105][105];

double solve(int r, int s, int p, int flag) {
	int tot = r + s + p;
	if ((flag == 0 && tot == r) || (flag == 1 && tot == s)
			|| (flag == 2 && tot == p))
		return 1.0;
	if ((flag == 0 && !r) || (flag == 1 && !s) || (flag == 2 && !p))
		return 0.0;
	if (vis[r][s][p])
		return dp[r][s][p];
	vis[r][s][p] = true;
	dp[r][s][p] = 0.0;
	double prob = 1.0;
	if (r && s) {
		double temp = (double) 2.0 * r * s / (tot * (tot - 1));
		dp[r][s][p] += solve(r, s - 1, p, flag) * temp;
		prob -= temp;
	}
	if (r && p) {
		double temp = (double) 2.0 * r * p / (tot * (tot - 1));
		dp[r][s][p] += solve(r - 1, s, p, flag) * temp;
		prob -= temp;
	}
	if (s && p) {
		double temp = (double) 2.0 * s * p / (tot * (tot - 1));
		dp[r][s][p] += solve(r, s, p - 1, flag) * temp;
		prob -= temp;
	}
	prob = 1.0 - prob;
	dp[r][s][p] /= prob;
	return dp[r][s][p];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int r, s, p;
	cin >> r >> s >> p;
	cout << fixed << setprecision(9);
	cout << solve(r, s, p, 0);
	memset(vis, 0, sizeof vis);
	cout << " " << solve(r, s, p, 1);
	memset(vis, 0, sizeof vis);
	cout << " " << solve(r, s, p, 2) << endl;
	return 0;
}
