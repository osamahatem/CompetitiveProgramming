/*
 * B. Bulbs.cpp
 *
 *  Created on: Oct 5, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int n, m;
char grid[405][405];

void toggle(int r, int c) {
	grid[r][c] = grid[r][c] == '0' ? '1' : '0';
	for (int i = r + 1; i < n; i++)
		grid[i][c] = grid[i][c] == '0' ? '1' : '0';
	for (int i = c - 1; i >= 0; i--)
		grid[r][i] = grid[r][i] == '0' ? '1' : '0';
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++)
			scanf("%s", grid[i]);
		int ans = 0;
		for (int i = 0; i < n; i++)
			for (int j = m - 1; j >= 0; j--)
				if (grid[i][j] == '0')
					ans++, toggle(i, j);
		printf("%d\n", ans);
	}
	return 0;
}
