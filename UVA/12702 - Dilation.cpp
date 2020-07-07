/*
 * 12702 - Dilation.cpp
 *
 *  Created on: Aug 9, 2014
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int t, ans[105][105], img[105][105], str[11][11];
	scanf("%d", &t);
	for (int tc = 1; tc <= t; tc++) {
		int n, m, s;
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				scanf("%d", &img[i][j]);
				ans[i][j] = img[i][j];
			}
		}
		scanf("%d%*d", &s);
		int orig = s / 2;
		for (int i = 0; i < s; i++)
			for (int j = 0; j < s; j++)
				scanf("%d", &str[i][j]);
		for (int r = 0; r < n; r++) {
			for (int c = 0; c < m; c++) {
				if (img[r][c] == 1) {
					int sr = r - orig, sc = c - orig;
					for (int i = 0; i < s; i++)
						for (int j = 0; j < s; j++)
							ans[i + sr][j + sc] |= str[i][j];
				}
			}
		}
		printf("Case %d:\n", tc);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (j)
					printf(" ");
				printf("%d", ans[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}
