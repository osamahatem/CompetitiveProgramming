/*
 * 510B. Fox And Two Dots.cpp
 *
 *  Created on: Feb 3, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int n, m, dr[] = { 1, -1, 0, 0 }, dc[] = { 0, 0, 1, -1 };
bool vis[55][55];
char grid[55][55];

bool inBound(int r, int c) {
	return (r >= 0 && r < n && c >= 0 && c < m);
}

bool solve(int pr, int pc, int cr, int cc) {
	vis[cr][cc] = 1;
	for (int i = 0; i < 4; i++) {
		int nr = cr + dr[i], nc = cc + dc[i];
		if (!inBound(nr, nc))
			continue;
		if (vis[nr][nc] && !(nr == pr && nc == pc))
			return true;
		if (!vis[nr][nc] && grid[cr][cc] == grid[nr][nc]
				&& solve(cr, cc, nr, nc))
			return true;
	}
	return false;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> grid[i];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			memset(vis, 0, sizeof vis);
			if (solve(i, j, i, j)) {
				cout << "Yes" << endl;
				return 0;
			}
		}
	}
	cout << "No" << endl;
	return 0;
}
