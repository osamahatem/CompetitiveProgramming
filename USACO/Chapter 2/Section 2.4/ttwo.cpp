/*
 ID: 19semse1
 PROG: ttwo
 LANG: C++
 */
/*
 * ttwo.cpp
 *
 *  Created on: Mar 12, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int dx[] = { -1, 0, 1, 0 }, dy[] = { 0, 1, 0, -1 };
bool vis[10][10][4][10][10][4];
char grid[11][11];

bool valid(int r, int c) {
	if (r < 0 || c < 0 || r == 10 || c == 10)
		return false;
	return grid[r][c] != '*';
}

int main() {
//#ifndef ONLINE_JUDGE
	freopen("ttwo.in", "r", stdin);
	freopen("ttwo.out", "w", stdout);
//#endif

	for (int i = 0; i < 10; i++)
		cin >> grid[i];
	int rc, cc, rf, cf, dc = 0, df = 0, ans = 0;
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			if (grid[i][j] == 'C')
				rc = i, cc = j;
			else if (grid[i][j] == 'F')
				rf = i, cf = j;
	while (!vis[rc][cc][dc][rf][cf][df] && !(rc == rf && cc == cf)) {
		ans++;
		vis[rc][cc][dc][rf][cf][df] = 1;
		int nr = rc + dx[dc], nc = cc + dy[dc];
		if (valid(nr, nc))
			rc = nr, cc = nc;
		else
			dc = (dc + 1) % 4;
		nr = rf + dx[df], nc = cf + dy[df];
		if (valid(nr, nc))
			rf = nr, cf = nc;
		else
			df = (df + 1) % 4;
	}
	cout << (vis[rc][cc][dc][rf][cf][df] ? 0 : ans) << endl;
	return 0;
}
