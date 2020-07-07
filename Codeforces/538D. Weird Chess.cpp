/*
 * 538D. Weird Chess.cpp
 *
 *  Created on: Apr 26, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int n;
char grid[55][55], moves[105][105];
bool vis[55][55];

void clean(int x, int y) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (grid[i][j] == '.') {
				int dx = i - x, dy = j - y;
				moves[n - 1 + dx][n - 1 + dy] = '.';
			}
}

void check(int x, int y) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (grid[i][j] == 'x') {
				int dx = i - x, dy = j - y;
				if (moves[n - 1 + dx][n - 1 + dy] == 'x')
					vis[i][j] = 1;
			}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> grid[i];
	for (int i = 0; i < 2 * n - 1; i++) {
		for (int j = 0; j < 2 * n - 1; j++)
			moves[i][j] = 'x';
		moves[i][2 * n - 1] = '\0';
	}
	moves[n - 1][n - 1] = 'o';
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			vis[i][j] = (grid[i][j] == 'x' ? 0 : 1);
			if (grid[i][j] == 'o')
				clean(i, j);
		}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (grid[i][j] == 'o')
				check(i, j);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (!vis[i][j]) {
				cout << "NO" << endl;
				return 0;
			}
	cout << "YES" << endl;
	for (int i = 0; i < 2 * n - 1; i++)
		cout << moves[i] << endl;
	return 0;
}
