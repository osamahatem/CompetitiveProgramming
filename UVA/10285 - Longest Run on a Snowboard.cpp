/*
 * 10285 - Longest Run on a Snowboard.cpp
 *
 *  Created on: Sep 17, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int R, C, arr[100][100], dp[100][100];
int dr[] = { 1, -1, 0, 0 }, dc[] = { 0, 0, 1, -1 };
char name[200];

int solve(int r, int c) {
	int& ret = dp[r][c];
	if (~ret)
		return ret;
	ret = 1;
	for (int i = 0; i < 4; i++) {
		int rr = r + dr[i], cc = c + dc[i];
		if (rr >= 0 && rr < R && cc >= 0 && cc < C && arr[rr][cc] < arr[r][c])
			ret = max(ret, 1 + solve(rr, cc));
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
	while (T--) {
		memset(dp, -1, sizeof dp);
		scanf("%s%d%d", name, &R, &C);
		for (int i = 0; i < R; i++)
			for (int j = 0; j < C; j++)
				scanf("%d", &arr[i][j]);
		int ans = 0;
		for (int i = 0; i < R; i++)
			for (int j = 0; j < C; j++)
				ans = max(ans, solve(i, j));
		printf("%s: %d\n", name, ans);
	}
	return 0;
}
