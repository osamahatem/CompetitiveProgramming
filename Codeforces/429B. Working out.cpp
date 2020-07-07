/*
 * 429B. Working out.cpp
 *
 *  Created on: Jul 20, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1005;

int grid[MAXN][MAXN];
int p1_from_start[MAXN][MAXN], p1_to_end[MAXN][MAXN];
int p2_from_start[MAXN][MAXN], p2_to_end[MAXN][MAXN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%d", &grid[i][j]);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			p1_from_start[i][j] = grid[i][j]
					+ max(p1_from_start[i - 1][j], p1_from_start[i][j - 1]);
	for (int i = n; i; i--)
		for (int j = m; j; j--)
			p1_to_end[i][j] = grid[i][j]
					+ max(p1_to_end[i + 1][j], p1_to_end[i][j + 1]);
	for (int i = n; i; i--)
		for (int j = 1; j <= m; j++)
			p2_from_start[i][j] = grid[i][j]
					+ max(p2_from_start[i + 1][j], p2_from_start[i][j - 1]);
	for (int i = 1; i <= n; i++)
		for (int j = m; j; j--)
			p2_to_end[i][j] = grid[i][j]
					+ max(p2_to_end[i - 1][j], p2_to_end[i][j + 1]);
	int ans = 0;
	for (int i = 2; i < n; i++)
		for (int j = 2; j < m; j++) {
			ans = max(ans,
					p1_from_start[i - 1][j] + p1_to_end[i + 1][j]
							+ p2_from_start[i][j - 1] + p2_to_end[i][j + 1]);
			ans = max(ans,
					p1_from_start[i][j - 1] + p1_to_end[i][j + 1]
							+ p2_from_start[i + 1][j] + p2_to_end[i - 1][j]);
		}
	printf("%d\n", ans);
	return 0;
}
