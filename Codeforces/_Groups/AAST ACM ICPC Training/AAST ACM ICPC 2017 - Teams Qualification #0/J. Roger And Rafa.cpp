/*
 * J. Roger And Rafa.cpp
 *
 *  Created on: Oct 2, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int n, m, q, dp[1005][1005];
char grid[1005][1005];

int solve(int x, int y) {
	int &ret = dp[x][y];
	if (~ret)
		return ret;
	set<int> grundy;
	for (int i = x + 1; i < n && i <= x + 5; i += 2)
		if (grid[i][y] == 'W')
			grundy.insert(solve(i, y));
	for (int i = y + 1; i < m && grid[x][i] == 'W' && i <= y + 3; i++)
		grundy.insert(solve(x, i));
	for (ret = 0; grundy.count(ret); ret++)
		;
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	freopen("roger.in", "r", stdin);
	int T;
	scanf("%d", &T);
	while (T--) {
		memset(dp, -1, sizeof dp);
		scanf("%d%d%d", &n, &m, &q);
		for (int i = 0; i < n; i++)
			scanf("%s", grid[i]);
		while (q--) {
			int k, x, y, ans = 0;
			scanf("%d", &k);
			while (k--) {
				scanf("%d%d", &x, &y);
				x--, y--;
				ans ^= solve(x, y);
			}
			printf("%s\n", ans ? "Roger" : "Rafael");
		}
	}
	return 0;
}
