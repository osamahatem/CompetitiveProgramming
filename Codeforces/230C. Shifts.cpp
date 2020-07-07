/*
 * 230C. Shifts.cpp
 *
 *  Created on: Jun 7, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

char grid[105][10005];
int mini[105][10005];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> grid[i];
		bool one = 0;
		for (int j = 0; j < m; j++) {
			mini[i][j] = 1 << 30;
			if (grid[i][j] == '1')
				one = 1;
		}
		if (!one) {
			cout << "-1" << endl;
			return 0;
		}
	}
	for (int i = 0; i < n; i++) {
		int s, c = 0;
		for (int j = 0; j < m; j++)
			if (grid[i][j] == '1') {
				s = j;
				break;
			}
		mini[i][s] = 0;
		for (int j = 0; j < m; j++) {
			c++;
			if (grid[i][(s + j) % m] == '1')
				c = 0;
			mini[i][(s + j) % m] = min(c, mini[i][(s + j) % m]);
		}
		for (int j = 0; j < m; j++) {
			c++;
			if (grid[i][(s - j + m) % m] == '1')
				c = 0;
			mini[i][(s - j + m) % m] = min(c, mini[i][(s - j + m) % m]);
		}
	}
	int ans = 1 << 30;
	for (int i = 0; i < m; i++) {
		int temp = 0;
		for (int j = 0; j < n; j++)
			temp += mini[j][i];
		ans = min(ans, temp);
	}
	cout << ans << endl;
	return 0;
}
