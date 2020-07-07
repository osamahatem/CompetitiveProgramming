/*
 * 359E. Neatness.cpp
 *
 *  Created on: Jul 28, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int n, x0, y0, t;
bool grid[500][500], vis[500][500];
string ans = "";
int dx[] = { 1, 0, -1, 0 }, dy[] = { 0, 1, 0, -1 };
char dl[] = { 'D', 'R', 'U', 'L' };

bool canMove(int x, int y, int dir) {
	for (int xx = x + dx[dir], yy = y + dy[dir];
			xx >= 0 && xx < n && yy >= 0 && yy < n;
			xx += dx[dir], yy += dy[dir])
		if (grid[xx][yy])
			return true;
	return false;
}

void solve(int x, int y) {
	vis[x][y] = 1;
	if (!grid[x][y])
		ans += "1", grid[x][y] = 1;
	for (int i = 0; i < 4; i++)
		if (canMove(x, y, i) && !vis[x + dx[i]][y + dy[i]]) {
			ans += dl[i];
			solve(x + dx[i], y + dy[i]);
			ans += dl[(i + 2) % 4];
		}
	ans += "2";
	grid[x][y] = 0;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	scanf("%d%d%d", &n, &x0, &y0);
	x0--, y0--;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			scanf("%d", &t);
			grid[i][j] = t;
		}
	solve(x0, y0);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (grid[i][j]) {
				printf("NO\n");
				return 0;
			}
	printf("YES\n%s\n", ans.c_str());
	return 0;
}
