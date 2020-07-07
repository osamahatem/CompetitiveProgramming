/*
 * WATER.cpp
 *
 *  Created on: Sep 22, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int R, C, grid[100][100], h;
bool vis[100][100];
int dr[] = { 1, -1, 0, 0 }, dc[] = { 0, 0, 1, -1 };

int BFS(int sr, int sc) {
	queue<int> Q;
	Q.push(sr);
	Q.push(sc);
	vis[sr][sc] = 1;
	int ret = 0;
	bool invalid = false;
	while (Q.size()) {
		int r = Q.front();
		Q.pop();
		int c = Q.front();
		Q.pop();
		if (r == 0 || r == R - 1 || c == 0 || c == C - 1)
			invalid = true;
		ret++;
		for (int i = 0; i < 4; i++) {
			int rr = r + dr[i], cc = c + dc[i];
			if (rr >= 0 && rr < R && cc >= 0 && cc < C && !vis[rr][cc]
					&& grid[rr][cc] <= h) {
				Q.push(rr);
				Q.push(cc);
				vis[rr][cc] = 1;
			}
		}
	}
	return invalid ? 0 : ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int T;
	scanf("%d", &T);
	while (T--) {
		int maxi = 0;
		scanf("%d%d", &R, &C);
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				scanf("%d", &grid[i][j]);
				maxi = max(maxi, grid[i][j]);
			}
		}
		int ans = 0;
		for (h = 1; h < maxi; h++) {
			memset(vis, 0, sizeof vis);
			for (int i = 0; i < R; i++) {
				for (int j = 0; j < C; j++) {
					if (!vis[i][j] && grid[i][j] <= h)
						ans += BFS(i, j);
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
