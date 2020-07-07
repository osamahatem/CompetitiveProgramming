/*
 * 758 - The Same Game.cpp
 *
 *  Created on: Sep 11, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int R = 10;
const int C = 15;

char grid[R + 5][C + 5];
int vis[R + 5][C + 5], id;
int dr[] = { 1, -1, 0, 0 }, dc[] = { 0, 0, 1, -1 };

int flood(int r, int c, bool t) {
	vis[r][c] = id;
	int ret = 1;
	for (int i = 0; i < 4; i++) {
		int rr = r + dr[i], cc = c + dc[i];
		if (rr >= 0 && r < R && c >= 0 && c < C && grid[rr][cc] == grid[r][c]
				&& vis[rr][cc] != id)
			ret += flood(rr, cc, t);
	}
	if (t)
		grid[r][c] = '#';
	return ret;
}

void update() {
	int r = R - 1, c = 0;
	for (int j = 0; j < C; j++) {
		bool empty = true;
		for (int i = R - 1; i >= 0; i--)
			if (grid[i][j] != '#')
				swap(grid[i][j], grid[r--][c]), empty = false;
		if (!empty)
			c++;
		r = R - 1;
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		for (int i = 0; i < R; i++)
			scanf("%s", grid[i]);
		if (t > 1)
			printf("\n");
		printf("Game %d:\n\n", t);
		int move = 0, score = 0, rem = R * C;
		while (1) {
			int best = 1, r = -1, c = -1;
			id++;
			for (int j = 0; j < C; j++)
				for (int i = R - 1; i >= 0; i--)
					if (grid[i][j] != '#' && vis[i][j] != id) {
						int x = flood(i, j, 0);
						if (x > best)
							best = x, r = i, c = j;
					}
			if (best == 1)
				break;
			int moveScore = (best - 2) * (best - 2);
			printf(
					"Move %d at (%d,%d): removed %d balls of color %c, got %d points.\n",
					++move, R - r, c + 1, best, grid[r][c], moveScore);
			score += moveScore, rem -= best, id++;
			flood(r, c, 1);
			update();
		}
		if (!rem)
			score += 1000;
		printf("Final score: %d, with %d balls remaining.\n", score, rem);
	}
	return 0;
}
