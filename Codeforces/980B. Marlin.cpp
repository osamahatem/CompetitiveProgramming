/*
 * 980B. Marlin.cpp
 *
 *  Created on: May 8, 2018
 *      Author: Osama Hatem
 */

/*
 * http://codeforces.com/blog/entry/59350
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

char grid[4][100];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;

	memset(grid, '.', sizeof grid);
	for (int i = 0; i < 4; i++)
		grid[i][n] = 0;

	if (k & 1) {
		grid[1][n / 2] = '#', k--;
		for (int i = n / 2 - 1, j = n / 2 + 1; i && k; i--, j++, k -= 2)
			grid[1][i] = grid[1][j] = '#';
		for (int i = 1; k; i++, k -= 2)
			grid[2][i] = grid[2][n - i - 1] = '#';
	} else
		for (int i = 1; k; i++, k -= 2)
			grid[1][i] = grid[2][i] = '#';

	cout << "YES" << endl;
	for (int i = 0; i < 4; i++)
		cout << grid[i] << endl;
	return 0;
}
