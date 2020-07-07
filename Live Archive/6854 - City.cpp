/*
 * 6854 - City.cpp
 *
 *  Created on: Oct 12, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int arr[505][505];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int T;
	scanf("%d", &T);
	while (T--) {
		int R, C, sr = -1, sc = -1;
		scanf("%d%d", &R, &C);
		for (int i = 0; i < R; i++)
			for (int j = 0; j < C; j++) {
				scanf("%d", &arr[i][j]);
				if (arr[i][j] == -1)
					sr = i, sc = j;
			}
		int ans = 0;
		for (int i = 0; i < R; i++)
			for (int j = 0; j < C; j++)
				if (i != sr || j != sc)
					ans += arr[i][j]
							* ((abs(i - sr) + abs(j - sc)) % 2 ? 1 : -1);
		printf("%d\n", ans);
	}
	return 0;
}
