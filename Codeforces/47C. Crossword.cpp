/*
 * 47C. Crossword.cpp
 *
 *  Created on: Aug 29, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

string all[6], ans = "";
char grid[35][35];

void check() {
	if (all[0].size() + all[2].size() != all[1].size() + 1
			|| all[3].size() + all[5].size() != all[4].size() + 1)
		return;
	memset(grid, '.', sizeof grid);
	int h = all[1].size(), w = all[4].size();
	int mh = all[0].size() - 1, mw = all[3].size() - 1;
	for (int i = 0; i < (int) all[3].size(); i++)
		grid[0][i] = all[3][i];
	for (int i = 0; i < (int) all[4].size(); i++)
		grid[mh][i] = all[4][i];
	for (int i = 0; i < (int) all[5].size(); i++)
		grid[h - 1][mw + i] = all[5][i];
	for (int i = 0; i < (int) all[0].size(); i++) {
		if (grid[i][0] != '.' && grid[i][0] != all[0][i])
			return;
		grid[i][0] = all[0][i];
	}
	for (int i = 0; i < (int) all[1].size(); i++) {
		if (grid[i][mw] != '.' && grid[i][mw] != all[1][i])
			return;
		grid[i][mw] = all[1][i];
	}
	for (int i = 0; i < (int) all[2].size(); i++) {
		if (grid[i + mh][w - 1] != '.' && grid[i + mh][w - 1] != all[2][i])
			return;
		grid[i + mh][w - 1] = all[2][i];
	}
	string temp;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++)
			temp += grid[i][j];
		temp += "\n";
	}
	if (!ans.size() || temp < ans)
		ans = temp;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	for (int i = 0; i < 6; i++)
		cin >> all[i];
	sort(all, all + 6);
	do {
		check();
	} while (next_permutation(all, all + 6));
	cout << (ans.size() ? ans : "Impossible") << endl;
	return 0;
}
