/*
 * 11953 - Battleships.cpp
 *
 *  Created on: Sep 11, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int dr[] = { 1, -1, 0, 0 }, dc[] = { 0, 0, 1, -1 };
int N;
char grid[105][105];
bool vis[105][105];

void DFS(int r, int c) {
	vis[r][c] = 1;
	for (int i = 0; i < 4; i++) {
		int rr = r + dr[i], cc = c + dc[i];
		if (rr >= 0 && r < N && c >= 0 && c < N && grid[rr][cc] != '.'
				&& !vis[rr][cc])
			DFS(rr, cc);
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
		memset(vis, 0, sizeof vis);
		scanf("%d", &N);
		for (int i = 0; i < N; i++)
			scanf("%s", grid[i]);
		int ans = 0;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				if (grid[i][j] == 'x' && !vis[i][j])
					DFS(i, j), ans++;
		printf("Case %d: %d\n", t, ans);
	}
	return 0;
}
