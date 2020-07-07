/*
 * 11487 - Gathering Food.cpp
 *
 *  Created on: Sep 18, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MOD = 20437;

char grid[15][15];
int n, t, dist[15][15], cnt[15][15];
bool vis[15][15];
int dr[] = { 1, -1, 0, 0 }, dc[] = { 0, 0, 1, -1 };

bool BFS(int sr, int sc, char tar) {
	memset(dist, 0, sizeof dist);
	memset(cnt, 0, sizeof cnt);
	memset(vis, 0, sizeof vis);
	dist[sr][sc] = 0, cnt[sr][sc] = 1, vis[sr][sc] = 1;
	queue<int> Q;
	Q.push(sr);
	Q.push(sc);
	while (Q.size()) {
		int r = Q.front();
		Q.pop();
		int c = Q.front();
		Q.pop();
		if (grid[r][c] == tar)
			return true;
		for (int i = 0; i < 4; i++) {
			int rr = r + dr[i], cc = c + dc[i];
			if (rr < 0 || rr == n || cc < 0 || cc == n)
				continue;
			if (grid[rr][cc] == '#'
					|| (grid[rr][cc] >= 'A' && grid[rr][cc] <= 'Z'
							&& grid[rr][cc] > tar))
				continue;
			if (!vis[rr][cc]) {
				Q.push(rr);
				Q.push(cc);
				vis[rr][cc] = 1, dist[rr][cc] = dist[r][c] + 1;
			}
			if (dist[rr][cc] == dist[r][c] + 1)
				cnt[rr][cc] = (cnt[r][c] + cnt[rr][cc]) % MOD;
		}
	}
	return false;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	while (scanf("%d", &n), n) {
		int sr = -1, sc = -1;
		for (int i = 0; i < n; i++) {
			scanf("%s", grid[i]);
			for (int j = 0; j < n; j++)
				if (grid[i][j] == 'A')
					sr = i, sc = j;
		}
		int len = 0, cntt = 1;
		bool val = 1;
		for (char ch = 'B'; ch <= 'Z'; ch++) {
			int r = -1, c = -1;
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					if (grid[i][j] == ch)
						r = i, c = j;
			if (r == -1 && c == -1)
				break;
			val &= BFS(sr, sc, ch);
			len += dist[r][c], cntt = cntt * cnt[r][c] % MOD;
			sr = r, sc = c;
		}
		printf("Case %d: ", ++t);
		if (val)
			printf("%d %d\n", len, cntt);
		else
			printf("Impossible\n");
	}
	return 0;
}
