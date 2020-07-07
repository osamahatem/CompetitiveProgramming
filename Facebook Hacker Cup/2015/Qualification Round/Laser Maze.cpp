/*
 * Laser Maze.cpp
 *
 *  Created on: Jan 11, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

struct state {
	int r, c, t;
};

char grid[105][105], dir[] = { '^', '>', 'v', '<', '#' };
bool vis[105][105][4], laz[105][105][4];
int R, C, dr[] = { -1, 0, 1, 0 }, dc[] = { 0, 1, 0, -1 };

bool inBound(int r, int c) {
	if (r == R || r < 0 || c == C || c < 0)
		return false;
	return true;
}

bool valid(int r, int c, int t) {
	if (!inBound(r, c) || find(dir, dir + 5, grid[r][c]) != dir + 5)
		return false;
	if (vis[r][c][t] || laz[r][c][t])
		return false;
	return true;
}

void laser(int r, int c) {
	int f = find(dir, dir + 4, grid[r][c]) - dir;
	if (f == 4)
		return;
	for (int i = 0; i < 4; i++) {
		int d = (f + i) % 4, tr = r, tc = c;
		do {
			laz[tr][tc][i] = 1;
			tr += dr[d], tc += dc[d];
		} while (inBound(tr, tc) && find(dir, dir + 5, grid[tr][tc]) == dir + 5);
	}
}

int BFS(int sr, int sc) {
	queue<state> Q;
	Q.push(state { sr, sc, 0 });
	int ans = 0;
	while (Q.size()) {
		int sz = Q.size();
		while (sz--) {
			int cr = Q.front().r, cc = Q.front().c, ct = Q.front().t;
			Q.pop();
			if (grid[cr][cc] == 'G')
				return ans;
			if (vis[cr][cc][ct])
				continue;
			vis[cr][cc][ct] = 1;
			int nt = (ct + 1) % 4;
			for (int i = 0; i < 4; i++) {
				int nr = cr + dr[i], nc = cc + dc[i];
				if (valid(nr, nc, nt))
					Q.push(state { nr, nc, nt });
			}
		}
		ans++;
	}
	return -1;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif

	int t, tc = 0;
	cin >> t;
	while (t--) {
		cout << "Case #" << ++tc << ": ";
		memset(vis, 0, sizeof vis);
		memset(laz, 0, sizeof laz);
		cin >> R >> C;
		for (int i = 0; i < R; i++)
			cin >> grid[i];
		int sr, sc;
		for (int i = 0; i < R; i++)
			for (int j = 0; j < C; j++)
				if (grid[i][j] == 'S')
					sr = i, sc = j;
				else
					laser(i, j);
		int ans = BFS(sr, sc);
		if (ans == -1)
			cout << "impossible" << endl;
		else
			cout << ans << endl;
	}
	return 0;
}
