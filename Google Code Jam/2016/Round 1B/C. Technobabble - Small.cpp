/*
 * C. Technobabble - Small.cpp
 *
 *  Created on: Apr 30, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int n;
pair<string, string> all[16];
int dp[1 << 16];

int solve(int mask) {
	if (mask == (1 << n) - 1)
		return 0;
	int &ret = dp[mask];
	if (ret != -1)
		return ret;
	ret = 0;
	for (int i = 0; i < n; i++) {
		if (mask & (1 << i))
			continue;
		bool a = 0, b = 0;
		for (int j = 0; j < n; j++) {
			if ((mask & (1 << j)) && all[i].first == all[j].first)
				a = 1;
			if ((mask & (1 << j)) && all[i].second == all[j].second)
				b = 1;
		}
		ret = max(ret, (a && b ? 1 : 0) + solve(mask | (1 << i)));
	}
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif

	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		memset(dp, -1, sizeof dp);
		cout << "Case #" << t << ": ";
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> all[i].first >> all[i].second;
		cout << solve(0) << endl;
	}
	return 0;
}
