/*
 * 1923. Scary Politics.cpp
 *
 *  Created on: Aug 6, 2014
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int n, m, dr[] = { 1, -1, 0, 0 }, dc[] = { 0, 0, 1, -1 };
int vis[55][55], id = 1;
char grid[55][55];

bool outOfBounds(int r, int c) {
	return (r < 0 || c < 0 || r == n || c == m);
}

void BFS(queue<pair<int, int> > &C, char x) {
	queue<pair<int, int> > Q = C;
	while (Q.size()) {
		int r = Q.front().first;
		int c = Q.front().second;
		Q.pop();
		if (vis[r][c] == id)
			continue;
		if (vis[r][c] == 0)
			C.push(make_pair(r, c));
		vis[r][c] = id;
		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i], nc = c + dc[i];
			if (outOfBounds(nr, nc) || vis[nr][nc] == id || grid[nr][nc] != x)
				continue;
			Q.push(make_pair(nr, nc));
		}
	}
	return;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%s", grid[i]);
	queue<pair<int, int> > C[2];
	bool turn = 0;
	C[0].push(make_pair(n - 1, 0));
	C[1].push(make_pair(0, m - 1));
	id++;
	BFS(C[0], grid[n - 1][0]);
	id++;
	BFS(C[1], grid[0][m - 1]);
	C[0].pop();
	C[1].pop();
	int l, x;
	scanf("%d", &l);
	while (l--) {
		id++;
		scanf("%d", &x);
		BFS(C[turn], x + '0');
		turn = !turn;
	}
	printf("%d\n%d\n", C[0].size(), C[1].size());
	return 0;
}
