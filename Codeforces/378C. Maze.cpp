/*
 * 378C. Maze.cpp
 *
 *  Created on: Jun 22, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

char grid[505][505];
int n, m, k, empty;
int dx[] = { 1, -1, 0, 0 }, dy[] = { 0, 0, 1, -1 };

bool valid(int r, int c) {
	return (r >= 0 && r < n && c >= 0 && c < m && grid[r][c] == 'X');
}

void solve(int r, int c) {
	if (empty == k)
		return;
	grid[r][c] = '.', empty--;
	for (int i = 0; i < 4; i++)
		if (valid(r + dx[i], c + dy[i]))
			solve(r + dx[i], c + dy[i]);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int sr, sc;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < n; i++) {
		scanf("%s", grid[i]);
		for (int j = 0; j < m; j++)
			if (grid[i][j] == '.') {
				grid[i][j] = 'X';
				empty++;
				sr = i, sc = j;
			}
	}
	solve(sr, sc);
	for (int i = 0; i < n; i++)
		printf("%s\n", grid[i]);
	return 0;
}
