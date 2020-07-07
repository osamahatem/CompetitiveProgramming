/*
 * A. Alphabet Cake.cpp
 *
 *  Created on: Apr 15, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

char grid[30][30];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif

	int T, r, c;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		scanf("%d%d", &r, &c);
		int rr = -1;
		for (int i = 0; i < r; i++) {
			scanf("%s", grid[i]);
			for (int j = 0; j < c; j++)
				if (grid[i][j] != '?' && rr == -1)
					rr = i;
		}
		for (int i = rr; i < r; i++) {
			bool empty = true;
			char C = 'A';
			for (int j = 0; j < c; j++)
				if (grid[i][j] != '?') {
					empty = false, C = grid[i][j];
					break;
				}
			for (int j = 0; j < c; j++) {
				if (empty)
					grid[i][j] = grid[i - 1][j];
				else if (grid[i][j] == '?')
					grid[i][j] = C;
				else
					C = grid[i][j];
			}
		}
		for (int i = rr - 1; ~i; i--)
			for (int j = 0; j < c; j++)
				grid[i][j] = grid[i + 1][j];
		printf("Case #%d:\n", t);
		for (int i = 0; i < r; i++)
			printf("%s\n", grid[i]);
	}
	return 0;
}
