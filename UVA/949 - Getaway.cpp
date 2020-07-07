/*
 * 949 - Getaway.cpp
 *
 *  Created on: Sep 13, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int R, C, invalid[100][100][4], vis[100][100][502], id;
int dr[] = { 1, -1, 0, 0 }, dc[] = { 0, 0, 1, -1 };

int BFS() {
	int steps = 0;
	queue<int> Q;
	vis[0][0][0] = id;
	Q.push(0);
	Q.push(0);
	while (Q.size()) {
		int sz = Q.size();
		while (sz -= 2, sz + 2) {
			int r = Q.front();
			Q.pop();
			int c = Q.front();
			Q.pop();
			if (r == R - 1 && c == C - 1)
				return steps;
			for (int i = 0; i < 4; i++) {
				if (invalid[r][c][i] == id)
					continue;
				int rr = r + dr[i], cc = c + dc[i], tt = min(steps + 1, 501);
				if (rr >= 0 && rr < R && cc >= 0 && cc < C
						&& vis[rr][cc][tt] != id) {
					vis[rr][cc][tt] = id;
					Q.push(rr);
					Q.push(cc);
				}
			}
			if (steps <= 500 && vis[r][c][steps + 1] != id) {
				Q.push(r);
				Q.push(c);
				vis[r][c][steps + 1] = id;
			}
		}
		steps++;
	}
	return -1;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	while (scanf("%d%d", &R, &C) != EOF) {
		id++;
		int ru, m;
		scanf("%d", &ru);
		while (ru--) {
			int x1, y1, x2, y2;
			scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
			for (int i = 0; i < 4; i++) {
				int xx = x1 + dr[i], yy = y1 + dc[i];
				if (xx == x2 && yy == y2)
					invalid[x1][y1][i] = id;
			}
		}
		scanf("%d", &m);
		while (m--) {
			int t, x, y;
			scanf("%d%d%d", &t, &x, &y);
			vis[x][y][t] = id;
		}
		printf("%d\n", BFS());
	}
	return 0;
}
