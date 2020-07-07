/*
 * A. Walking around Berhattan.cpp
 *
 *  Created on: Nov 16, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int n, m, b[105][105];
int dr[] = { 0, 1, 0, -1 }, dc[] = { 1, 0, -1, 0 };
int tar_r[][2] = { { 0, -1 }, { 0, 0 }, { -1, 0 }, { -1, -1 } };
int tar_c[][2] = { { 0, 0 }, { 0, -1 }, { -1, -1 }, { -1, 0 } };
bool vis[105][105];
char moves[505];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%1d", &b[i][j]);
	scanf("%s", moves);
	int dir = 0, x = 0, y = 0, ans = 0;
	for (int i = 0; moves[i]; i++) {
		if (moves[i] == 'R')
			dir = (dir + 1) % 4;
		else if (moves[i] == 'L')
			dir = (dir + 3) % 4;
		else {
			for (int k = 0; k < 2; k++) {
				int nx = x + tar_r[dir][k], ny = y + tar_c[dir][k];
				if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
					ans += vis[nx][ny] ? b[nx][ny] / 2 : b[nx][ny];
					vis[nx][ny] = 1;
				}
			}
			x += dr[dir], y += dc[dir];
		}
	}
	printf("%d\n", ans);
	return 0;
}
