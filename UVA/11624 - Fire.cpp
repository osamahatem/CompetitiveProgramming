/*
 * 11624 - Fire.cpp
 *
 *  Created on: Mar 28, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int R, C;
char maze[1005][1005];
bool vis[1005][1005];
int dr[] = { 0, 0, 1, -1 }, dc[] = { 1, -1, 0, 0 };

bool valid(int r, int c) {
	if (r < 0 || r == R || c < 0 || c == C)
		return false;
	return maze[r][c] == '.' && !vis[r][c];
}

struct node {
	int r, c;bool fire;
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int T;
	scanf("%d", &T);
	while (T--) {
		queue<node> Q;
		memset(vis, 0, sizeof vis);
		scanf("%d%d", &R, &C);
		for (int i = 0; i < R; i++)
			scanf("%s", maze[i]);
		for (int i = 0; i < R; i++)
			for (int j = 0; j < C; j++)
				if (maze[i][j] == 'F')
					Q.push(node { i, j, 1 });
		for (int i = 0; i < R; i++)
			for (int j = 0; j < C; j++)
				if (maze[i][j] == 'J')
					Q.push(node { i, j, 0 }), vis[i][j] = 1;
		int ans = -1, steps = 0;
		while (ans == -1 && Q.size()) {
			steps++;
			int sz = (int) Q.size();
			while (ans == -1 && sz--) {
				node cur = Q.front();
				Q.pop();
				int r = cur.r, c = cur.c;
				if (cur.fire)
					maze[r][c] = 'F';
				else if (r == 0 || r == R - 1 || c == 0 || c == C - 1) {
					ans = steps;
					break;
				}
				for (int i = 0; i < 4; i++) {
					int nr = r + dr[i], nc = c + dc[i];
					if (valid(nr, nc))
						Q.push(node { nr, nc, cur.fire }), vis[nr][nc] = 1;
				}
			}
		}
		if (ans == -1)
			printf("IMPOSSIBLE\n");
		else
			printf("%d\n", ans);
	}
	return 0;
}
