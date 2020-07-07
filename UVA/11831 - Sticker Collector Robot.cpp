/*
 * 11831 - Sticker Collector Robot.cpp
 *
 *  Created on: Sep 10, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int n, m, dx[] = { -1, 0, 1, 0 }, dy[] = { 0, 1, 0, -1 };
char grid[105][105], S[50005];
string dir = "NLSO";

bool valid(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m && grid[x][y] != '#';
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	while (scanf("%d%d%*d", &n, &m), n && m) {
		int sx = -1, sy = -1, sd = 0, ans = 0;
		for (int i = 0; i < n; i++) {
			scanf("%s", grid[i]);
			for (int j = 0; j < m; j++) {
				int d = dir.find(grid[i][j]);
				if (d != -1)
					sx = i, sy = j, sd = d;
			}
		}
		scanf("%s", S);
		for (int i = 0; S[i]; i++) {
			if (S[i] == 'D')
				sd = (sd + 1) % 4;
			else if (S[i] == 'E')
				sd = (sd + 3) % 4;
			else {
				int nx = sx + dx[sd], ny = sy + dy[sd];
				if (valid(nx, ny)) {
					sx = nx, sy = ny;
					ans += grid[sx][sy] == '*';
					grid[sx][sy] = '.';
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
