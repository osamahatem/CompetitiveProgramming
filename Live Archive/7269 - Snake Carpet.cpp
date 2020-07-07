/*
 * 7269 - Snake Carpet.cpp
 *
 *  Created on: Sep 24, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int n, h, w;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	while (scanf("%d", &n) != EOF) {
		vector<vector<int>> ans(n + 1, vector<int>());
		int cells = n * (n + 1) / 2;
		if (cells % 2) {
			h = (n + 1) / 2;
			w = cells / h;
			for (int i = 1; i <= n; i += 2) {
				int len = (i + 1) / 2;
				for (int j = 1; j <= len; j++) {
					ans[i].push_back(len);
					ans[i].push_back(j);
				}
				for (int j = len - 1; j; j--) {
					ans[i].push_back(j);
					ans[i].push_back(len);
				}
			}
			int c = h + 1;
			int ne = (n & 1 ? n - 1 : n);
			if (ne == n) {
				for (int i = 1; i <= h; i++) {
					ans[n].push_back(i);
					ans[n].push_back(c);
				}
				c++;
				for (int i = h; i; i--) {
					ans[n].push_back(i);
					ans[n].push_back(c);
				}
				c++;
				ne -= 2;
			}
			for (int i = 2; i < ne; i += 2, ne -= 2) {
				for (int j = 1; j <= i / 2; j++) {
					ans[i].push_back(j);
					ans[i].push_back(c);
				}
				for (int j = i / 2 + 1; j <= h; j++) {
					ans[ne].push_back(j);
					ans[ne].push_back(c);
				}
				c++;
				for (int j = i / 2; j; j--) {
					ans[i].push_back(j);
					ans[i].push_back(c);
				}
				for (int j = h; j > i / 2; j--) {
					ans[ne].push_back(j);
					ans[ne].push_back(c);
				}
				c++;
			}
		} else {
			int dr[] = { 1, 0, -1, 0 }, dc[] = { 0, 1, 0, 1 }, dir = 0;
			int r = 1, c = 1;
			h = 2, w = cells / 2;
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= i; j++) {
					ans[i].push_back(r);
					ans[i].push_back(c);
					r += dr[dir], c += dc[dir];
					dir = (dir + 1) % 4;
				}
			}
		}
		printf("%d %d\n", h, w);
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < (int) ans[i].size(); j++) {
				if (j)
					printf(" ");
				printf("%d", ans[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}
