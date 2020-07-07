/*
 * 11094 - Continents.cpp
 *
 *  Created on: Sep 11, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int R, C, dr[] = { 1, -1, 0, 0 }, dc[] = { 0, 0, 1, -1 };
char grid[25][25], land;
bool vis[25][25];

int DFS(int r, int c) {
	vis[r][c] = 1;
	int ret = 1;
	for (int i = 0; i < 4; i++) {
		int rr = r + dr[i], cc = (c + dc[i] + C) % C;
		if (rr >= 0 && rr < R && !vis[rr][cc] && grid[rr][cc] == land)
			ret += DFS(rr, cc);
	}
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	while (scanf("%d%d", &R, &C) != EOF) {
		memset(vis, 0, sizeof vis);
		for (int i = 0; i < R; i++)
			scanf("%s", grid[i]);
		int x, y, ans = 0;
		scanf("%d%d", &x, &y);
		land = grid[x][y];
		DFS(x, y);
		for (int i = 0; i < R; i++)
			for (int j = 0; j < C; j++)
				if (grid[i][j] == land && !vis[i][j])
					ans = max(ans, DFS(i, j));
		printf("%d\n", ans);
	}
	return 0;
}
