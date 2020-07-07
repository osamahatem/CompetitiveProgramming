/*
 * A. Falling Balls.cpp
 *
 *  Created on: May 19, 2018
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int c, cnt[105], tar[105];
char grid[105][105];

int main() {
//#ifndef ONLINE_JUDGE
//	freopen("in.in", "r", stdin);
////	freopen("out.out", "w", stdout);
//#endif

	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> c;
		for (int i = 0; i < c; i++)
			cin >> cnt[i];

		cout << "Case #" << t << ": ";
		if (cnt[0] == 0 || cnt[c - 1] == 0) {
			cout << "IMPOSSIBLE" << endl;
			continue;
		}

		int cur = 0;
		for (int i = 0; i < c; i++) {
			for (int j = 0; j < cnt[i]; j++)
				tar[cur++] = i;
		}

		memset(grid, '.', sizeof grid);

		for (int i = 0; i < c; i++) {
			int inc = 1;
			char ramp = '\\';
			if (tar[i] < i)
				inc = -1, ramp = '/';
			for (int j = i; j != tar[i]; j += inc)
				grid[abs(i - j)][j] = ramp;
		}

		int cc = c;
		bool flag = true;
		while (flag) {
			for (int i = 0; i < c; i++)
				if (grid[cc - 1][i] != '.')
					flag = false;
			if (flag)
				cc--;
		}
		cout << ++cc << endl;
		for (int i = 0; i < cc; i++) {
			grid[i][c] = 0;
			cout << grid[i] << endl;
		}
	}
	return 0;
}
