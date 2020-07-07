/*
 * 847I. Noise Level.cpp
 *
 *  Created on: Sep 27, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int n, m, q, p, ans, vis[255][255], id;
char grid[255][255];
int dr[] = { 1, -1, 0, 0 }, dc[] = { 0, 0, 1, -1 };

bool check(int sr, int sc) {
	if (grid[sr][sc] == '*')
		return false;
	queue<int> Q;
	Q.push(sr);
	Q.push(sc);
	vis[sr][sc] = ++id;
	int total = 0;
	for (int i = 0; total <= p && ((26 * q) >> i) > 0; i++) {
		int sz = Q.size() / 2;
		while (sz--) {
			int r = Q.front();
			Q.pop();
			int c = Q.front();
			Q.pop();
			if (grid[r][c] != '.')
				total += (q * (grid[r][c] - 'A' + 1)) >> i;
			for (int i = 0; i < 4; i++) {
				int nr = r + dr[i], nc = c + dc[i];
				if (nr < 0 || nr >= n || nc < 0 || nc >= m
						|| grid[nr][nc] == '*' || vis[nr][nc] == id)
					continue;
				vis[nr][nc] = id;
				Q.push(nr);
				Q.push(nc);
			}
		}
	}
	return total > p;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	scanf("%d%d%d%d", &n, &m, &q, &p);
	for (int i = 0; i < n; i++)
		scanf("%s", grid[i]);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			ans += check(i, j);
	printf("%d\n", ans);
	return 0;
}
