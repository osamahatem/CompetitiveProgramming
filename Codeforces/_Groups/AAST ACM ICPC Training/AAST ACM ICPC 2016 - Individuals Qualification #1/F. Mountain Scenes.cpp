/*
 * F. Mountain Scenes.cpp
 *
 *  Created on: Aug 29, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MOD = 1e9 + 7;

int dp[2][10001];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, w, h;
	cin >> n >> w >> h;
	for (int i = 0; i <= n; i++)
		dp[0][i] = 1 + i;
	for (int ii = 1, i = 1; ii <= w; ii++, i ^= 1) {
		for (int j = 0; j <= n; j++) {
			dp[i][j] = dp[i ^ 1][j] - (h < j ? dp[i ^ 1][j - h - 1] : 0);
			dp[i][j] = (dp[i][j] + MOD) % MOD;
			dp[i][j] = (dp[i][j] + (j ? dp[i][j - 1] : 0)) % MOD;
		}
	}
	int ans = dp[w & 1][n] - (n ? dp[w & 1][n - 1] : 0);
	ans = (ans - min(h, n / w) - 1 + MOD) % MOD;
	cout << ans << endl;
	return 0;
}
