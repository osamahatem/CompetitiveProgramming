/*
 ID: 19semse1
 PROG: castle
 LANG: C++
 */
/*
 * castle.cpp
 *
 *  Created on: Mar 7, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int R, C, dr[] = { 0, -1, 0, 1 }, dc[] = { -1, 0, 1, 0 };
char grid[105][105];
bool vis[105][105];
int id[105][105], area[10005], rooms = 0, maxi = 0;

int dfs(int r, int c) {
	vis[r][c] = 1;
	id[r][c] = rooms;
	int ret = ((r % 2 && c % 2 ? 1 : 0));
	for (int i = 0; i < 4; i++) {
		int nr = r + dr[i], nc = c + dc[i];
		if (!vis[nr][nc] && grid[nr][nc] != '#')
			ret += dfs(nr, nc);
	}
	return ret;
}

int main() {
//#ifndef ONLINE_JUDGE
	freopen("castle.in", "r", stdin);
	freopen("castle.out", "w", stdout);
//#endif

	memset(grid, '#', sizeof grid);
	cin >> C >> R;
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++) {
			int walls, cr = i * 2 + 1, cc = j * 2 + 1;
			grid[cr][cc] = ' ';
			cin >> walls;
			for (int d = 0; d < 4; d++)
				if (!(walls & (1 << d)))
					grid[cr + dr[d]][cc + dc[d]] = ' ';
		}
	for (int i = 1; i < 2 * R; i++)
		for (int j = 1; j < 2 * C; j++)
			if (grid[i][j] != '#' && !vis[i][j]) {
				int a = dfs(i, j);
				maxi = max(maxi, a);
				area[rooms++] = a;
			}
	cout << rooms << endl << maxi << endl;
	maxi = 0;
	int x, y;
	char c;
	for (int j = 1; j < 2 * C; j++) {
		for (int i = 2 * R - 1; i > 0; i--) {
			if (grid[i][j] != '#')
				continue;
			if (grid[i - 1][j] != '#' && grid[i + 1][j] != '#'
					&& id[i - 1][j] != id[i + 1][j]
					&& area[id[i - 1][j]] + area[id[i + 1][j]] > maxi) {
				maxi = area[id[i - 1][j]] + area[id[i + 1][j]];
				x = i / 2 + 1, y = (j + 1) / 2, c = 'N';
			} else if (grid[i][j - 1] != '#' && grid[i][j + 1] != '#'
					&& id[i][j - 1] != id[i][j + 1]
					&& area[id[i][j - 1]] + area[id[i][j + 1]] > maxi) {
				maxi = area[id[i][j - 1]] + area[id[i][j + 1]];
				x = i / 2 + 1, y = (j + 1) / 2, c = 'E';
			}
		}
	}
	cout << maxi << endl << x << " " << y << " " << c << endl;
	return 0;
}
