/*
 * 404D. Minesweeper 1D.cpp
 *
 *  Created on: Jun 18, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e6 + 5;
const int MOD = 1000000007;
const int ZERO = 0, ONE_FREE = 1, ONE_OCC = 2, TWO = 3, MINE = 4;

long long dp[MAXN][5];
map<char, int> mp;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	mp['0'] = ZERO, mp['1'] = ONE_FREE, mp['2'] = TWO, mp['*'] = MINE;
	string in;
	cin >> in;
	for (int i = 0; i < 5; i++)
		dp[0][i] = (
				((in[0] != '?' && mp[in[0]] != i) || i == ONE_OCC || i == TWO) ?
						0 : 1);
	for (int i = 1; i < (int) in.size(); i++) {
		if (in[i] == '0' || in[i] == '?')
			dp[i][ZERO] = (dp[i - 1][ZERO] + dp[i - 1][ONE_OCC]) % MOD;
		if (in[i] == '1' || in[i] == '?') {
			dp[i][ONE_FREE] = (dp[i - 1][ZERO] + dp[i - 1][ONE_OCC]) % MOD;
			dp[i][ONE_OCC] = dp[i - 1][MINE];
		}
		if (in[i] == '2' || in[i] == '?')
			dp[i][TWO] = dp[i - 1][MINE];
		if (in[i] == '*' || in[i] == '?')
			dp[i][MINE] = (dp[i - 1][ONE_FREE] + dp[i - 1][TWO]
					+ dp[i - 1][MINE]) % MOD;
	}
	long long ans = 0;
	for (int i = 0; i < 5; i++)
		ans += dp[(int) in.size() - 1][i];
	ans -= dp[(int) in.size() - 1][ONE_FREE] + dp[(int) in.size() - 1][TWO];
	cout << ans % MOD << endl;
	return 0;
}
