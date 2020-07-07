/*
 * 690B1. Recover Polygon (easy).cpp
 *
 *  Created on: Jul 10, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int n, grid[55][55];

bool valid(int r, int c, int val) {
	return r < 0 || c < 0 || r >= n || c >= n || grid[r][c] == val;
}

bool check(int r, int c, int x, int y) {
	for (int i = 0; i < x; i++)
		for (int j = 0; j < y; j++)
			if (grid[r + i][c + j] != 4)
				return false;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if ((i < r - 1 || j < c - 1 || i > r + x || j > c + y)
					&& !valid(i, j, 0))
				return false;
	for (int i = 0; i < x; i++)
		if (!valid(r + i, c - 1, 2) || !valid(r + i, c + y, 2))
			return false;
	for (int i = 0; i < y; i++)
		if (!valid(r - 1, c + i, 2) || !valid(r + x, c + i, 2))
			return false;
	return valid(r - 1, c - 1, 1) && valid(r - 1, c + y, 1)
			&& valid(r + x, c - 1, 1) && valid(r + x, c + y, 1);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%1d", &grid[i][j]);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (int x = 0; i + x < n; x++)
				for (int y = 0; j + y < n; y++)
					if (check(i, j, x + 1, y + 1)) {
						printf("Yes\n");
						return 0;
					}
	printf("No\n");
	return 0;
}
