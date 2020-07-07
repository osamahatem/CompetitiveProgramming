/*
 * 12291 - Polyomino Composer.cpp
 *
 *  Created on: Aug 27, 2014
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int n, m, dr[] = { 0, 0, 1, -1 }, dc[] = { 1, -1, 0, 0 };
char l[11][11], s[11][11];

bool val(int r, int c) {
	return (r >= 0 && r < n && c >= 0 && c < n);
}

bool check(int r, int c) {
	int x, y;
	for (int i = 0; i < 4; i++) {
		x = r + dr[i], y = c + dc[i];
		if (val(x, y) && l[x][y] == '2')
			return true;
	}
	return false;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	while (scanf("%d%d", &n, &m), n) {
		for (int i = 0; i < n; i++)
			scanf("%s", l[i]);
		for (int i = 0; i < m; i++)
			scanf("%s", s[i]);
		int lr, lc, sr, sc, cnt = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (l[i][j] == '*')
					lr = i, lc = j;
		for (int i = 0; i < m; i++)
			for (int j = 0; j < m; j++)
				if (s[i][j] == '*')
					cnt++, sr = i, sc = j;
		int dr = lr - sr, dc = lc - sc;
		for (int i = 0; i < m; i++)
			for (int j = 0; j < m; j++)
				if (s[i][j] == '*' && l[i + dr][j + dc] == '*')
					l[i + dr][j + dc] = '1';
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (l[i][j] == '*')
					lr = i, lc = j;
		dr = lr - sr, dc = lc - sc;
		for (int i = 0; i < m; i++)
			for (int j = 0; j < m; j++)
				if (s[i][j] == '*' && l[i + dr][j + dc] == '*')
					l[i + dr][j + dc] = '2';
		bool flag = 1, flag1 = 0, flag2 = 0;
		int cnt1 = 0, cnt2 = 0;
		for (int i = 0; i < n; i++) {
//			printf("%s\n", l[i]);
			for (int j = 0; j < n; j++)
				if (l[i][j] == '*')
					flag = 0;
				else if (l[i][j] == '1')
					cnt1++, flag1 |= check(i, j);
				else if (l[i][j] == '2')
					cnt2++;
		}
		flag1 &= (cnt == cnt1);
		flag2 = (cnt == cnt2);
		printf("%d\n", flag & flag1 & flag2);
	}
	return 0;
}
