/*
 * 549D. Haar Features.cpp
 *
 *  Created on: Jun 6, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int n, m, val[105][105];
char grid[105][105];

void fil(int h, int w, int v) {
	for (int i = 0; i <= h; i++)
		for (int j = 0; j <= w; j++)
			val[i][j] += v;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> grid[i];
	int ans = 0;
	for (int j = m - 1; j >= 0; j--) {
		for (int i = n - 1; i >= 0; i--)
			if (grid[i][j] == 'W' && val[i][j] != 1)
				ans++, fil(i, j, 1 - val[i][j]);
			else if (grid[i][j] == 'B' && val[i][j] != -1)
				ans++, fil(i, j, -1 - val[i][j]);
	}
	cout << ans << endl;
	return 0;
}
