/*
 * 543A. Writing Code.cpp
 *
 *  Created on: May 7, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int n, m, b, mod, dp[2][505][505], bugs[505];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin >> m >> n >> b >> mod;
	for (int i = 0; i < m; i++)
		cin >> bugs[i];
	for (int i = 0; i <= b; i++)
		dp[0][0][i] = dp[1][0][i] = 1;
	for (int i = m - 1; i >= 0; i--) {
		for (int l = 0; l <= n; l++) {
			for (int bb = 0; bb <= b; bb++) {
				dp[i % 2][l][bb] = dp[(i + 1) % 2][l][bb];
				if (bb >= bugs[i] && l) {
					dp[i % 2][l][bb] += dp[i % 2][l - 1][bb - bugs[i]];
					dp[i % 2][l][bb] %= mod;
				}
			}
		}
	}
	cout << dp[0][n][b] << endl;
	return 0;
}
