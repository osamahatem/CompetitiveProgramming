/*
 * 318D. Ants.cpp
 *
 *  Created on: Dec 22, 2014
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int dx[] = { 0, 0, -1, 1 }, dy[] = { 1, -1, 0, 0 };
int grid[2][150][150];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//  freopen("out.out", "w", stdout);
#endif

	int n, q, x, y, cnt;
	bool l = 0;
	cin >> n >> q;
	grid[0][75][75] = n;
	do {
		cnt = 0;
		memset(grid[!l], 0, sizeof grid[!l]);
		for (int i = 0; i < 150; i++)
			for (int j = 0; j < 150; j++) {
				if (grid[l][i][j] == 0)
					continue;
				if (grid[l][i][j] < 4) {
					grid[!l][i][j] += grid[l][i][j];
					continue;
				}
				cnt++;
				grid[!l][i][j] += grid[l][i][j] % 4;
				for (int d = 0; d < 4; d++)
					grid[!l][i + dx[d]][j + dy[d]] += grid[l][i][j] / 4;
			}
		l = !l;
	} while (cnt);
	while (q--) {
		cin >> x >> y;
		x += 75, y += 75;
		if (x >= 0 && x < 150 && y >= 0 && y < 150)
			cout << grid[l][x][y] << endl;
		else
			cout << "0" << endl;
	}
	return 0;
}
