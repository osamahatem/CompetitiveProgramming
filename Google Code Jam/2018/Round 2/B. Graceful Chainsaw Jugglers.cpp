/*
 * B. Graceful Chainsaw Jugglers.cpp
 *
 *  Created on: May 19, 2018
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int dp[35][505][505];

int solve(int idx, int r, int b) {
	if (idx > r)
		return 0;

	int &ret = dp[idx][r][b];
	if (~ret)
		return ret;
	ret = 0;
	int sr = 0, sb = 0;
	for (int i = 0; sr + idx <= r && sb + i <= b; i++) {
		sr += idx, sb += i;
		ret = max(ret, solve(idx + 1, r - sr, b - sb) + i + 1);
	}
	return ret;
}

int main() {
//#ifndef ONLINE_JUDGE
//	freopen("in.in", "r", stdin);
////	freopen("out.out", "w", stdout);
//#endif

	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	memset(dp, -1, sizeof dp);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		int r, b;
		cin >> r >> b;
		cout << "Case #" << t << ": " << solve(0, r, b) - 1 << endl;
	}
	return 0;
}
