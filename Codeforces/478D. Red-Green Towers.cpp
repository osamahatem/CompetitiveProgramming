/*
 * 478D. Red-Green Towers.cpp
 *
 *  Created on: May 21, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXR = 2e5 + 5;
const int MOD = 1e9 + 7;

int r, g;
int dp[2][MAXR];

bool check(int h) {
	int x = r, y = g;
	for (int i = h; i; i--) {
		if (y > x)
			swap(x, y);
		if (x < i)
			return false;
		x -= i;
	}
	return true;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin >> r >> g;
	int s = 1, e = 1000;
	while (s < e) {
		int mid = (s + e + 1) / 2;
		if (check(mid))
			s = mid;
		else
			e = mid - 1;
	}
	for (int i = 0; i <= r; i++)
		dp[s & 1][i] = 1;
	for (int h = s - 1; ~h; h--) {
		for (int rr = 0; rr <= r; rr++) {
			int used = h * (h + 1) / 2;
			int gg = g - (used - r + rr);
			int i = h & 1;
			int ii = i ^ 1;
			dp[i][rr] = 0;
			if (h + 1 <= rr)
				dp[i][rr] = (dp[i][rr] + dp[ii][rr - h - 1]) % MOD;
			if (h + 1 <= gg)
				dp[i][rr] = (dp[i][rr] + dp[ii][rr]) % MOD;
		}
	}
	cout << dp[0][r] << endl;
	return 0;
}
