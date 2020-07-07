/*
 * BOND.cpp
 *
 *  Created on: Jan 26, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int n;
double dp[1 << 20], prob[20][20];
bool vis[1 << 20];

double solve(int mask) {
	if (!mask)
		return 1.0;
	if (vis[mask])
		return dp[mask];
	vis[mask] = 1;
	double &ret = dp[mask] = 0.0;
	int jb = 0;
	for (int i = 0; i < n; i++)
		jb += (bool) (!(mask & (1 << i)));
	for (int i = 0; i < n; i++) {
		if (!(mask & (1 << i)))
			continue;
		ret = max(ret, prob[jb][i] * solve(mask ^ (1 << i)));
	}
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> prob[i][j], prob[i][j] /= 100.0;
	cout << fixed << setprecision(6);
	cout << solve((1 << n) - 1) * 100.0 << endl;
	return 0;
}
