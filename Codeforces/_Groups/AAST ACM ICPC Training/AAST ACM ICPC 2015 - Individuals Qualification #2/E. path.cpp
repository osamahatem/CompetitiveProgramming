/*
 * E. path.cpp
 *
 *  Created on: Sep 7, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int dr[] = { 1, -1, 0, 0 }, dc[] = { 0, 0, 1, -1 };
bool vis[105][105];
char grid[105][105];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	freopen("path.in", "r", stdin);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		memset(vis, 0, sizeof vis);
		int R, C, ans = -1, sr, sc, er, ec;
		bool flag = 0;
		cin >> R >> C;
		for (int i = 0; i < R; i++) {
			cin >> grid[i];
			for (int j = 0; j < C; j++)
				if (grid[i][j] == 'S')
					sr = i, sc = j;
				else if (grid[i][j] == 'E')
					er = i, ec = j;
		}
		queue<int> Q;
		Q.push(sr);
		Q.push(sc);
		vis[sr][sc] = 1;
		while (Q.size()) {
			ans++;
			int sz = Q.size() / 2;
			while (sz--) {
				int r = Q.front();
				Q.pop();
				int c = Q.front();
				Q.pop();
				if (r == er && c == ec) {
					while (Q.size())
						Q.pop();
					flag = 1;
					break;
				}
				for (int i = 0; i < 4; i++) {
					int nr = r + dr[i], nc = c + dc[i];
					if (nr < 0 || nr >= R || nc < 0 || nc >= C || vis[nr][nc]
							|| grid[nr][nc] == '*')
						continue;
					Q.push(nr);
					Q.push(nc);
					vis[nr][nc] = 1;
				}
			}
		}
		cout << "Case " << t << ": " << (!flag ? -1 : ans) << endl;
	}
	return 0;
}
