/*
 * 908B. New Year and Buggy Bot.cpp
 *
 *  Created on: Dec 29, 2017
 *      Author: Osama Hatem
 */
 
/*
http://codeforces.com/blog/entry/56713
*/

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int dr[] = { 1, 0, -1, 0 };
const int dc[] = { 0, 1, 0, -1 };

int n, m, sr, sc, er, ec, dir[4];
char grid[55][55];

bool valid(int r, int c) {
	return ~r && ~c && r < n && c < m && grid[r][c] != '#';
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> grid[i];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (grid[i][j] == 'S')
				sr = i, sc = j;
			else if (grid[i][j] == 'E')
				er = i, ec = j;
	string op;
	cin >> op;
	string mp = "0123";
	int ans = 0;
	do {
		for (int i = 0; i < 4; i++)
			dir[i] = mp.find('0' + i);
		int r = sr, c = sc;
		bool flag = true;
		for (int i = 0; i < (int) op.size(); i++) {
			int d = dir[op[i] - '0'];
			if (!valid(r + dr[d], c + dc[d])) {
				flag = false;
				break;
			}
			r += dr[d], c += dc[d];
			if (grid[r][c] == 'E')
				break;
		}
		if (flag && grid[r][c] == 'E')
			ans++;
	} while (next_permutation(mp.begin(), mp.end()));
	cout << ans << endl;
	return 0;
}
