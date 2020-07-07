/*
 * 2.Crosswords.cpp
 *
 *  Created on: Dec 14, 2014
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int r, c;
char grid[55][55];

int main() {
//#ifndef ONLINE_JUDGE
	freopen("crosswords.in", "r", stdin);
	freopen("crosswords.out", "w", stdout);
//#endif

	set<pair<int, int> > ans;
	set<pair<int, int> >::iterator it;
	cin >> r >> c;
	for (int i = 0; i <= r; i++)
		grid[i][0] = '#';
	for (int i = 0; i <= c; i++)
		grid[0][i] = '#';
	for (int i = 1; i <= r; i++)
		cin >> (grid[i] + 1);
	for (int i = 0; i <= r; i++) {
		for (int j = 0; j <= c; j++) {
			if (grid[i][j] != '#')
				continue;
			if (i + 3 <= r && grid[i + 1][j] == '.' && grid[i + 2][j] == '.'
					&& grid[i + 3][j] == '.')
				ans.insert(make_pair(i + 1, j));
			if (j + 3 <= c && grid[i][j + 1] == '.' && grid[i][j + 2] == '.'
					&& grid[i][j + 3] == '.')
				ans.insert(make_pair(i, j + 1));
		}
	}
	cout << ans.size() << endl;
	for (it = ans.begin(); it != ans.end(); it++)
		cout << it->first << " " << it->second << endl;
	return 0;
}
