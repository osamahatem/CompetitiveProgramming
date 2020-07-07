/*
 * SNSOCIAL.cpp
 *
 *  Created on: May 31, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int R, C, grid[505][505];
int dist[505][505];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &R, &C);
		for (int i = 0; i < R; i++)
			for (int j = 0; j < C; j++)
				scanf("%d", &grid[i][j]);
		memset(dist, 127, sizeof dist);
		int maxi = 0;
		queue<int> Q;
		for (int i = 0; i < R; i++)
			for (int j = 0; j < C; j++)
				maxi = max(maxi, grid[i][j]);
		for (int i = 0; i < R; i++)
			for (int j = 0; j < C; j++)
				if (grid[i][j] == maxi) {
					Q.push(i);
					Q.push(j);
					dist[i][j] = 0;
				}
		int ans = 0;
		while (Q.size()) {
			int sz = Q.size();
			while (sz -= 2, sz + 2) {
				int r = Q.front();
				Q.pop();
				int c = Q.front();
				Q.pop();
				for (int i = -1; i <= 1; i++) {
					for (int j = -1; j <= 1; j++) {
						int nr = r + i, nc = c + j;
						if (nr < 0 || nr == R || nc < 0 || nc == C)
							continue;
						if (dist[r][c] + 1 < dist[nr][nc]) {
							Q.push(nr);
							Q.push(nc);
							dist[nr][nc] = dist[r][c] + 1;
						}
					}
				}
			}
			ans++;
		}
		printf("%d\n", --ans);
	}
	return 0;
}
