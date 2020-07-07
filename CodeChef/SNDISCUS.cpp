/*
 * SNDISCUS.cpp
 *
 *  Created on: Jun 1, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int N = 51;

int dr[] = { 1, -1, 0, 0 }, dc[] = { 0, 0, 1, -1 };
int n, dist[N][N];

void BFS(int x1, int y1, int x2, int y2) {
	int temp[N][N];
	memset(temp, 127, sizeof temp);
	queue<int> Q;
	for (int i = x1; i <= x2; i++) {
		for (int j = y1; j <= y2; j++) {
			Q.push(i);
			Q.push(j);
			temp[i][j] = 0;
		}
	}
	while (Q.size()) {
		int r = Q.front();
		Q.pop();
		int c = Q.front();
		Q.pop();
		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i], nc = c + dc[i];
			if (nr < 0 || nr == N || nc < 0 || nc == N)
				continue;
			if (temp[r][c] + 1 < temp[nr][nc]) {
				Q.push(nr);
				Q.push(nc);
				temp[nr][nc] = temp[r][c] + 1;
			}
		}
	}
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			dist[i][j] = max(dist[i][j], temp[i][j]);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int T;
	scanf("%d", &T);
	while (T--) {
		memset(dist, 0, sizeof dist);
		scanf("%d", &n);
		while (n--) {
			int x1, y1, x2, y2;
			scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
			if (x1 > x2)
				swap(x1, x2);
			if (y1 > y2)
				swap(y1, y2);
			BFS(x1, y1, x2, y2);
		}
		int ans = 1 << 28;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				ans = min(ans, dist[i][j]);
		printf("%d\n", ans);
	}
	return 0;
}
