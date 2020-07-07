/*
 * 10913 - Walking on a Grid.cpp
 *
 *  Created on: Sep 18, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int n, k, t, arr[75][75], dp[75][75][6][3];
bool vis[75][75][6][3];

int solve(int r, int c, int left, int dir) {
	if (left < 0 || r < 0 || r == n || c < 0 || c == n)
		return -(1 << 29);
	if (r == n - 1 && c == n - 1 && (left || arr[r][c] >= 0))
		return arr[r][c];
	int& ret = dp[r][c][left][dir];
	if (vis[r][c][left][dir])
		return ret;
	vis[r][c][left][dir] = 1;
	ret = solve(r + 1, c, left - (arr[r][c] < 0), 0);
	if (dir != 1)
		ret = max(ret, solve(r, c + 1, left - (arr[r][c] < 0), 2));
	if (dir != 2)
		ret = max(ret, solve(r, c - 1, left - (arr[r][c] < 0), 1));
	if (ret == -(1 << 29))
		return ret;
	ret += arr[r][c];
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	while (scanf("%d%d", &n, &k), n || k) {
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				scanf("%d", &arr[i][j]);
		memset(vis, 0, sizeof vis);
		int ans = solve(0, 0, k, 0);
		printf("Case %d: ", ++t);
		if (ans > -(1 << 29))
			printf("%d\n", ans);
		else
			printf("impossible\n");
	}
	return 0;
}
