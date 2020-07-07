/*
 ID: 19semse1
 PROG: maze1
 LANG: C++
 */
/*
 * maze1.cpp
 *
 *  Created on: Mar 12, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

char grid[205][80];
int w, h, dist[205][80];
int dw[] = { 1, 0, -1, 0 }, dh[] = { 0, 1, 0, -1 };
bool vis[205][80];

bool valid(int r, int c) {
	if (r < 0 || c < 0 || r == h || c == w)
		return false;
	if (grid[r][c] != ' ')
		return false;
	return !vis[r][c];

}

void bfs(int sr, int sc) {
	int d = 0, r, c;
	queue<pair<int, int> > Q;
	Q.push(make_pair(sr, sc));
	while (Q.size()) {
		d++;
		int sz = Q.size();
		while (sz--) {
			r = Q.front().first, c = Q.front().second;
			Q.pop();
			if (vis[r][c])
				continue;
			dist[r][c] = min(dist[r][c], d);
			vis[r][c] = 1;
			for (int i = 0; i < 4; i++)
				if (valid(r + dh[i], c + dw[i]))
					Q.push(make_pair(r + dh[i], c + dw[i]));
		}
	}
}

int main() {
//#ifndef ONLINE_JUDGE
	freopen("maze1.in", "r", stdin);
	freopen("maze1.out", "w", stdout);
//#endif

	cin >> w >> h;
	gets(grid[0]);
	w = w * 2 + 1, h = h * 2 + 1;
	for (int i = 0; i < h; i++)
		gets(grid[i]);
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
			dist[i][j] = 1 << 30;
	for (int i = 0; i < h; i++)
		if (grid[i][0] == ' ')
			bfs(i, 0), memset(vis, 0, sizeof vis);
		else if (grid[i][w - 1] == ' ')
			bfs(i, w - 1), memset(vis, 0, sizeof vis);
	for (int i = 0; i < w; i++)
		if (grid[0][i] == ' ')
			bfs(0, i), memset(vis, 0, sizeof vis);
		else if (grid[h - 1][i] == ' ')
			bfs(h - 1, i), memset(vis, 0, sizeof vis);
	int ans = 0;
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
			if (grid[i][j] == ' ')
				ans = max(ans, dist[i][j]);
	cout << ans / 2 << endl;
	return 0;
}
