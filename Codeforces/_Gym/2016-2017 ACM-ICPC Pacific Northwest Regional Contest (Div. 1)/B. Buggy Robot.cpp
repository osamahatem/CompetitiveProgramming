/*
 * B. Buggy Robot.cpp
 *
 *  Created on: Oct 10, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

struct node {
	int r, c, l, d;
};

char grid[55][55], str[55];
int dr[] = { 1, -1, 0, 0 }, dc[] = { 0, 0, 1, -1 };
string dir = "DURL";
int n, m, len, dist[55][55][55], sr, sc, er, ec;

bool valid(int r, int c) {
	return r >= 0 && r < n && c >= 0 && c < m && grid[r][c] != '#';
}

void BFS(int sr, int sc) {
	memset(dist, -1, sizeof dist);
	deque<node> Q;
	Q.push_back( { sr, sc, 0, 0 });
	while (Q.size()) {
		node cur = Q.front();
		Q.pop_front();
		int r = cur.r, c = cur.c, l = cur.l, d = cur.d;
		if (dist[r][c][l] != -1)
			continue;
		dist[r][c][l] = d;
		if (r == er && c == ec) {
			dist[er][ec][len] = d;
			return;
		}
		int com = l < len ? dir.find(str[l]) : -1;
		int nr = -1, nc = -1;
		if (com > -1)
			nr = r + dr[com], nc = c + dc[com];
		if (!valid(nr, nc))
			nr = r, nc = c;
		if (dist[nr][nc][min(len, l + 1)] == -1)
			Q.push_front(node { nr, nc, min(len, l + 1), d });
		if (dist[r][c][min(len, l + 1)] == -1)
			Q.push_back(node { r, c, min(len, l + 1), d + 1 });
		for (int i = 0; i < 4; i++) {
			if (i == com)
				continue;
			nr = r + dr[i], nc = c + dc[i];
			if (!valid(nr, nc))
				nr = r, nc = c;
			if (dist[nr][nc][l] == -1)
				Q.push_back(node { nr, nc, l, d + 1 });
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%s", grid[i]);
	scanf("%s", str);
	len = strlen(str);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (grid[i][j] == 'R')
				sr = i, sc = j;
			else if (grid[i][j] == 'E')
				er = i, ec = j;
	BFS(sr, sc);
	printf("%d\n", dist[er][ec][len]);
	return 0;
}
