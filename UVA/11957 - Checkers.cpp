/*
 * 11957 - Checkers.cpp
 *
 *  Created on: Sep 18, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MOD = 1000007;

int n, dp[100][100], dr[] = { -1, -1 }, dc[] = { 1, -1 };
char grid[101][101];

bool valid(int r, int c) {
	return r >= 0 && r < n && c >= 0 && c < n && grid[r][c] == '.';
}

int solve(int r, int c) {
	if (!r)
		return 1;
	int& ret = dp[r][c];
	if (~ret)
		return ret;
	ret = 0;
	for (int i = 0; i < 2; i++) {
		int rr = r + dr[i], cc = c + dc[i];
		int rrr = rr + dr[i], ccc = cc + dc[i];
		if (valid(rr, cc))
			ret = (ret + solve(rr, cc)) % MOD;
		else if (valid(rrr, ccc))
			ret = (ret + solve(rrr, ccc)) % MOD;
	}
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		memset(dp, -1, sizeof dp);
		int sr = -1, sc = -1;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%s", grid[i]);
			for (int j = 0; j < n; j++)
				if (grid[i][j] == 'W')
					sr = i, sc = j;
		}
		printf("Case %d: %d\n", t, solve(sr, sc));
	}
	return 0;
}
