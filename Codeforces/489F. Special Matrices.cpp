/*
 * 489F. Special Matrices.cpp
 *
 *  Created on: Jun 20, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 505;

long long dp[MAXN][MAXN];
int colCnt[MAXN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, m, mod;
	cin >> n >> m >> mod;
	dp[0][0] = 1;
	int C0 = 0, C1 = 0;
	for (int i = 0; i < m; i++) {
		string temp;
		cin >> temp;
		for (int j = 0; j < n; j++)
			colCnt[j] += (temp[j] == '1');
	}
	for (int i = 0; i < n; i++)
		C1 += (colCnt[i] == 1), C0 += (colCnt[i] == 0);
	for (int c0 = 0; c0 <= n; c0++) {
		for (int c1 = 0; c1 <= n; c1++) {
			if (c1 > 1)
				dp[c0][c1] += dp[c0][c1 - 2] * c1 * (c1 - 1) / 2;
			if (c0)
				dp[c0][c1] += dp[c0 - 1][c1] * c0 * c1;
			if (c0 > 1)
				dp[c0][c1] += dp[c0 - 2][c1 + 2] * c0 * (c0 - 1) / 2;
			dp[c0][c1] %= mod;
		}
	}
	cout << dp[C0][C1] << endl;
	return 0;
}
