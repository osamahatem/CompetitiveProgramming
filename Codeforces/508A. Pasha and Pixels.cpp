/*
 * 508A. Pasha and Pixels.cpp
 *
 *  Created on: Jan 27, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int n, m;
bool grid[1005][1005];

bool check(int r, int c) {
	if (r < 0 || c < 0 || r + 1 >= n || c + 1 >= m)
		return false;
	return grid[r][c] && grid[r + 1][c] && grid[r][c + 1] && grid[r + 1][c + 1];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int r, c, k;
	cin >> n >> m >> k;
	for (int i = 0; i < k; i++) {
		cin >> r >> c;
		grid[--r][--c] = 1;
		bool l = check(r - 1, c - 1) || check(r - 1, c) || check(r, c - 1)
				|| check(r, c);
		if (l) {
			cout << ++i << endl;
			return 0;
		}
	}
	cout << "0" << endl;
	return 0;
}
