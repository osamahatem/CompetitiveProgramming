/*
 * G. Rainbow Zamboni.cpp
 *
 *  Created on: Aug 31, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

char grid[2001][2001];

int dc[] = { 0, 1, 0, -1 }, dr[] = { -1, 0, 1, 0 };

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int r, c, i, j, n, s = 1, d = 0;
	cin >> r >> c >> i >> j >> n;
	i--, j--;
	char co = 'A';
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++)
			grid[i][j] = '.';
		grid[i][c] = 0;
	}
	while (n--) {
		for (int ss = 0; ss < s; ss++) {
			grid[i][j] = co;
			i = (i + dr[d] + r) % r;
			j = (j + dc[d] + c) % c;
		}
		s++, co++, d++;
		if (co > 'Z')
			co = 'A';
		if (d > 3)
			d = 0;
	}
	grid[i][j] = '@';
	for (int i = 0; i < r; i++)
		printf("%s\n", grid[i]);
	return 0;
}
