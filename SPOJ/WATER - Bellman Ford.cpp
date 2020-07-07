/*
 * WATER - Bellman Ford.cpp
 *
 *  Created on: Sep 22, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int R, C, grid[100][100], dist[100][100];
int dr[] = { 1, -1, 0, 0 }, dc[] = { 0, 0, 1, -1 };

void bellman() {
	memset(dist, 127, sizeof dist);
	queue<int> Q;
	vector<vector<int>> inQ(R, vector<int>(C, 0));
	for (int i = 0; i < R; i++) {
		dist[i][0] = grid[i][0], dist[i][C - 1] = grid[i][C - 1];
		inQ[i][0]++, inQ[i][C - 1]++;
		Q.push(i);
		Q.push(0);
		Q.push(i);
		Q.push(C - 1);
	}
	for (int i = 0; i < C; i++) {
		dist[0][i] = grid[0][i], dist[R - 1][i] = grid[R - 1][i];
		inQ[0][i]++, inQ[R - 1][i];
		Q.push(0);
		Q.push(i);
		Q.push(R - 1);
		Q.push(i);
	}
	while (Q.size()) {
		int r = Q.front();
		Q.pop();
		int c = Q.front();
		Q.pop();
		inQ[r][c]--;
		for (int i = 0; i < 4; i++) {
			int rr = r + dr[i], cc = c + dc[i];
			if (rr < 0 || rr == R || cc < 0 || cc == C)
				continue;
			if (max(dist[r][c], grid[rr][cc]) < dist[rr][cc]) {
				dist[rr][cc] = max(dist[r][c], grid[rr][cc]);
				if (!inQ[rr][cc]) {
					Q.push(rr);
					Q.push(cc);
					inQ[rr][cc]++;
				}
			}
		}
	}
}

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
		bellman();
		int ans = 0;
		for (int i = 0; i < R; i++)
			for (int j = 0; j < C; j++)
				ans += dist[i][j] - grid[i][j];
		printf("%d\n", ans);
	}
	return 0;
}
