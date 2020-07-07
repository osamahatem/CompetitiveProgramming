/*
 * 4473 - Brothers.cpp
 *
 *  Created on: Sep 21, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int N, R, C, K;
int grid[105][105], temp[105][105];
int dr[] = { 1, -1, 0, 0 }, dc[] = { 0, 0, 1, -1 };

bool valid(int r, int c) {
	return (r >= 0 && r < R && c >= 0 && c < C);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	while (scanf("%d%d%d%d", &N, &R, &C, &K), N) {
		for (int i = 0; i < R; i++)
			for (int j = 0; j < C; j++)
				scanf("%d", &grid[i][j]);
		while (K--) {
			memcpy(temp, grid, sizeof temp);
			for (int i = 0; i < R; i++)
				for (int j = 0; j < C; j++)
					for (int d = 0; d < 4; d++) {
						int nr = i + dr[d], nc = j + dc[d];
						if (valid(nr, nc)
								&& temp[nr][nc] == (temp[i][j] + 1) % N)
							grid[nr][nc] = temp[i][j];
					}
		}
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (j)
					printf(" ");
				printf("%d", grid[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}
