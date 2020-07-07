/*
 * 314 - Robot.cpp
 *
 *  Created on: Sep 13, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int R, C, grid[51][51], vis[51][51][4], id, sr, sc, sd, er, ec;
int dr[] = { -1, 0, 1, 0 }, dc[] = { 0, -1, 0, 1 };
vector<string> dir = { "north", "west", "south", "east" };
char initDir[10];

int BFS() {
	queue<int> Q;
	Q.push(sr);
	Q.push(sc);
	Q.push(sd);
	vis[sr][sc][sd] = id;
	int steps = 0;
	while (Q.size()) {
		int sz = Q.size();
		while (sz) {
			sz -= 3;
			int r = Q.front();
			Q.pop();
			int c = Q.front();
			Q.pop();
			int d = Q.front();
			Q.pop();
			if (r == er && c == ec)
				return steps;
			int rr = r, cc = c;
			for (int i = 0; i < 3; i++) {
				rr += dr[d], cc += dc[d];
				if (rr > 0 && rr < R && cc > 0 && cc < C) {
					if (grid[rr][cc] != id && vis[rr][cc][d] != id) {
						vis[rr][cc][d] = id;
						Q.push(rr);
						Q.push(cc);
						Q.push(d);
					} else if (grid[rr][cc] == id)
						break;
				}
			}
			d = (d + 1) % 4;
			if (vis[r][c][d] != id) {
				vis[r][c][d] = id;
				Q.push(r);
				Q.push(c);
				Q.push(d);
			}
			d = (d + 2) % 4;
			if (vis[r][c][d] != id) {
				vis[r][c][d] = id;
				Q.push(r);
				Q.push(c);
				Q.push(d);
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

	while (scanf("%d%d", &R, &C), R) {
		id++;
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				int x;
				scanf("%d", &x);
				if (x) {
					grid[i][j] = id;
					grid[i][j + 1] = id;
					grid[i + 1][j] = id;
					grid[i + 1][j + 1] = id;
				}
			}
		}
		scanf("%d%d%d%d%s", &sr, &sc, &er, &ec, initDir);
		sd = find(dir.begin(), dir.end(), initDir) - dir.begin();
		printf("%d\n", BFS());
	}
	return 0;
}
