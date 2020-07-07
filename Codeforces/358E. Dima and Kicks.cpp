/*
 * 358E. Dima and Kicks.cpp
 *
 *  Created on: Aug 3, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int n, m, grid[1005][1005], dx[] = { 1, -1, 0, 0 }, dy[] = { 0, 0, 1, -1 };
bool vis[1005][1005];

void DFS(int x, int y) {
	vis[x][y] = 1;
	for (int d = 0; d < 4; d++) {
		int xx = x + dx[d], yy = y + dy[d];
		if (xx >= 0 && x < n && yy >= 0 && yy < m && grid[xx][yy]
				&& !vis[xx][yy])
			DFS(xx, yy);
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif
	int sx = -1, sy = -1;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			scanf("%d", &grid[i][j]);
			if (grid[i][j])
				sx = i, sy = j;
		}

	int odd = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (grid[i][j]) {
				int cnt = 0;
				for (int d = 0; d < 4; d++) {
					int ii = i + dx[d], jj = j + dy[d];
					if (ii >= 0 && ii < n && jj >= 0 && jj < m)
						cnt += grid[ii][jj] == 1;
				}
				odd += cnt & 1;
			}
	DFS(sx, sy);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (grid[i][j] && !vis[i][j])
				odd = 3;

	int gcd = -1;
	for (int i = 0; i < n; i++) {
		int last = 0, len = 0;
		for (int j = 0; j < m; j++) {
			if (grid[i][j] && !last)
				len = 0;
			if (grid[i][j])
				len++;
			else if (len > 1)
				gcd = (gcd != -1 ? __gcd(gcd, len - 1) : len - 1);
			last = grid[i][j];
		}
		if (len > 1)
			gcd = (gcd != -1 ? __gcd(gcd, len - 1) : len - 1);
	}
	for (int j = 0; j < m; j++) {
		int last = 0, len = 0;
		for (int i = 0; i < n; i++) {
			if (grid[i][j] && !last)
				len = 0;
			if (grid[i][j])
				len++;
			else if (len > 1)
				gcd = (gcd != -1 ? __gcd(gcd, len - 1) : len - 1);
			last = grid[i][j];
		}
		if (len > 1)
			gcd = (gcd != -1 ? __gcd(gcd, len - 1) : len - 1);
	}

	if ((odd != 0 && odd != 2) || gcd == 1 || gcd == -1) {
		printf("-1\n");
		return 0;
	}
	bool sp = 0;
	for (int i = 2; i <= gcd; i++) {
		if (gcd % i == 0) {
			if (sp)
				printf(" ");
			printf("%d", i);
			sp = 1;
		}
	}
	printf("\n");
	return 0;
}
