/*
 * 589J. Cleaner Robot.cpp
 *
 *  Created on: Oct 28, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const string DIRS = "URDL";

int dr[] = { -1, 0, 1, 0 }, dc[] = { 0, 1, 0, -1 }, R, C;
bool vis[10][10][4];
char grid[11][11];

bool valid(int r, int c) {
	return (r >= 0 && r < R && c >= 0 && c < C && grid[r][c] != '*');
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int sr, sc, sd;
	scanf("%d%d", &R, &C);
	for (int i = 0; i < R; i++) {
		scanf("%s", grid[i]);
		for (int j = 0; j < C; j++)
			if (grid[i][j] != '.' && grid[i][j] != '*')
				sr = i, sc = j, sd = find(DIRS.begin(), DIRS.end(), grid[i][j])
						- DIRS.begin();
	}
	queue<pair<int, pair<int, int>>> Q;
	Q.push(make_pair(sd, make_pair(sr, sc)));
	set<pair<int, int>> ans;
	while (Q.size()) {
		int cd = Q.front().first;
		int cr = Q.front().second.first;
		int cc = Q.front().second.second;
		Q.pop();
		if (vis[cr][cc][cd])
			break;
		vis[cr][cc][cd] = 1;
		ans.insert(make_pair(cr, cc));
		int nr = cr + dr[cd], nc = cc + dc[cd];
		if (valid(nr, nc))
			Q.push(make_pair(cd, make_pair(nr, nc)));
		else
			Q.push(make_pair((++cd) % 4, make_pair(cr, cc)));
	}
	printf("%d\n", ans.size());
	return 0;
}
