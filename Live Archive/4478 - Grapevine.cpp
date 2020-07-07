/*
 * 4478 - Grapevine.cpp
 *
 *  Created on: Sep 21, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int R, C, grid[501][501], low, high, Q;

bool check(int side) {
	int r1 = R - 1, r2 = R - 1;
	for (int c1 = 0; c1 + side - 1 < C; c1++) {
		int c2 = c1 + side - 1;
		while (r1 >= 0 && grid[r1][c1] >= low)
			r1--;
		while (r2 >= 0 && grid[r2][c2] > high)
			r2--;
		if (r2 - r1 >= side)
			return true;
	}
	return false;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	while (scanf("%d %d", &R, &C), R) {
		for (int i = 0; i < R; i++)
			for (int j = 0; j < C; j++)
				scanf("%d", &grid[i][j]);
		scanf("%d", &Q);
		while (Q--) {
			scanf("%d %d", &low, &high);
			int s = 0, e = min(R, C);
			while (s < e) {
				int mid = (s + e + 1) / 2;
				if (check(mid))
					s = mid;
				else
					e = mid - 1;
			}
			printf("%d\n", s);
		}
		printf("-\n");
	}
	return 0;
}
