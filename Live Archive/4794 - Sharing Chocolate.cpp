/*
 * 4794 - Sharing Chocolate.cpp
 *
 *  Created on: Feb 16, 2018
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int n, x, y, sz[15], area[1 << 15], dp[101][1 << 15];

int solve(int x, int mask) {
	if (!(mask & (mask - 1)))
		return 1;
	int y = area[mask] / x;
	if (x > y)
		swap(x, y);
	int &ret = dp[x][mask];
	if (~ret)
		return ret;
	for (int m = mask & (mask - 1); m; m = (m - 1) & mask) {
		if (area[m] % x == 0 && solve(x, m) && solve(x, mask ^ m))
			return ret = 1;
		if (area[m] % y == 0 && solve(y, m) && solve(y, mask ^ m))
			return ret = 1;
	}
	return ret = 0;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int T = 0;
	while (cin >> n, n) {
		cin >> x >> y;
		for (int i = 0; i < n; i++)
			cin >> sz[i];

		memset(area, 0, sizeof area);
		for (int i = 0; i < (1 << n); i++)
			for (int j = 0; j < n; j++)
				area[i] += sz[j] * ((i >> j) & 1);

		memset(dp, -1, sizeof dp);
		bool ans = (area[(1 << n) - 1] == x * y) && (solve(x, (1 << n) - 1));
		cout << "Case " << ++T << ": " << (ans ? "Yes" : "No") << endl;
	}
	return 0;
}
