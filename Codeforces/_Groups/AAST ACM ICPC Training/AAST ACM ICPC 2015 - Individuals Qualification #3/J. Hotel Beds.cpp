/*
 * J. Hotel Beds.cpp
 *
 *  Created on: Sep 10, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int dp[12][4100][55], n, m, bed[13], w[13];

int solve(int idx, int mask, int left) {
	if (mask == (1 << m) - 1 || idx == n)
		return 0;
	int &ret = dp[idx][mask][left];
	if (ret != -1)
		return ret;
	ret = solve(idx + 1, mask, bed[idx + 1]);
	for (int i = 0; i < m; i++) {
		if ((mask & (1 << i)) || w[i] > left)
			continue;
		ret = max(ret, 1 + solve(idx, mask | (1 << i), left - w[i]));
	}
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	freopen("hotel.in", "r", stdin);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		memset(dp, -1, sizeof dp);
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			cin >> bed[i];
			bed[i] /= 10;
		}
		for (int i = 0; i < m; i++) {
			cin >> w[i];
			w[i] /= 10;
		}
		cout << "Case " << t << ": " << solve(0, 0, bed[0]) << endl;
	}
	return 0;
}
