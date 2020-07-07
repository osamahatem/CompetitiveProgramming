/*
 * 586D. Phillip and Trains.cpp
 *
 *  Created on: Oct 12, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int n, k, dp[3][105];
char grid[3][105];

int solve(int r, int c) {
	if (c + 1 >= n)
		return 1;
	int &ret = dp[r][c];
	if (ret != -1)
		return ret;
	ret = 0;
	if (grid[r][c + 1] != '.')
		return ret;
	bool f1 = 1;
	for (int cc = 2; cc < 4 && cc + c < n; cc++)
		if (grid[r][c + cc] != '.')
			f1 = 0;
	if (f1)
		ret |= solve(r, c + 3);
	if (r - 1 >= 0) {
		f1 = 1;
		for (int cc = 1; cc < 4 && cc + c < n; cc++)
			if (grid[r - 1][c + cc] != '.')
				f1 = 0;
		if (f1)
			ret |= solve(r - 1, c + 3);
	}
	if (r + 1 < 3) {
		f1 = 1;
		for (int cc = 1; cc < 4 && cc + c < n; cc++)
			if (grid[r + 1][c + cc] != '.')
				f1 = 0;
		if (f1)
			ret |= solve(r + 1, c + 3);
	}
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int t;
	cin >> t;
	while (t--) {
		int s = 0;
		cin >> n >> k;
		for (int i = 0; i < 3; i++) {
			cin >> grid[i];
			if (grid[i][0] == 's')
				s = i;
		}
		memset(dp, -1, sizeof dp);
		cout << (solve(s, 0) ? "YES" : "NO") << endl;
	}
	return 0;
}
