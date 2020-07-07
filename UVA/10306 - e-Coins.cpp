/*
 * 10306 - e-Coins.cpp
 *
 *  Created on: Sep 28, 2014
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int n, s, dp[300][300];
pair<int, int> all[40];

int solve(int x, int y) {
	if (x * x + y * y > s)
		return 1 << 28;
	if (x * x + y * y == s)
		return 0;
	int &ret = dp[x][y];
	if (ret != -1)
		return ret;
	ret = 1 << 28;
	for (int i = 0; i < n; i++) {
		if (all[i].first == 0 && all[i].second == 0)
			continue;
		ret = min(ret, 1 + solve(x + all[i].first, y + all[i].second));
	}
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int t;
	cin >> t;
	while (t--) {
		memset(dp, -1, sizeof dp);
		cin >> n >> s;
		s *= s;
		for (int i = 0; i < n; i++)
			cin >> all[i].first >> all[i].second;
		int ans = solve(0, 0);
		if (ans >= 1 << 28)
			cout << "not possible\n";
		else
			cout << ans << "\n";
	}
	return 0;
}
