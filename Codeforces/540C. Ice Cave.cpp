/*
 * 540C. Ice Cave.cpp
 *
 *  Created on: Apr 30, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

struct node {
	int r, c;
};

int n, m, tr, tc, sr, sc;
int dr[] = { -1, 1, 0, 0 }, dc[] = { 0, 0, 1, -1 };
char grid[505][505];
int vis[505][505];

bool valid(int r, int c) {
	return (r >= 0 && r < n && c >= 0 && c < m);
}

bool BFS() {
	queue<node> Q;
	Q.push(node { sr, sc });
	vis[sr][sc] = -1;
	while (!Q.empty()) {
		node cur = Q.front();
		Q.pop();
		int ct = (grid[cur.r][cur.c] == '.' ? 0 : 1);
		if (cur.r == tr && cur.c == tc && vis[cur.r][cur.c] + ct == 1)
			return true;
		if (vis[cur.r][cur.c] + ct == 1)
			continue;
		vis[cur.r][cur.c]++;
		for (int i = 0; i < 4; i++) {
			int nr = cur.r + dr[i], nc = cur.c + dc[i];
			if (valid(nr, nc))
				Q.push(node { nr, nc });
		}
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
	cin >> sr >> sc >> tr >> tc;
	sr--, sc--, tr--, tc--;
	cout << (BFS() ? "YES" : "NO") << endl;
	return 0;
}
