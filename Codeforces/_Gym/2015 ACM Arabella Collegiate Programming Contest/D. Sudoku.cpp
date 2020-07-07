/*
 * D. Sudoku.cpp
 *
 *  Created on: Aug 29, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int t;
	cin >> t;
	while (t--) {
		char grid[10][10];
		for (int i = 0; i < 9; i++)
			cin >> grid[i];
		bool flag = 1;
		for (int i = 0; i < 9; i += 3)
			for (int j = 0; j < 9; j += 3) {
				set<char> ss;
				for (int ii = 0; ii < 3; ii++)
					for (int jj = 0; jj < 3; jj++)
						ss.insert(grid[i + ii][j + jj]);
				if (ss.size() != 9)
					flag = 0;
			}
		for (int i = 0; i < 9; i++) {
			set<char> col, row;
			for (int j = 0; j < 9; j++)
				row.insert(grid[i][j]), col.insert(grid[j][i]);
			if (row.size() != 9 || col.size() != 9)
				flag = 0;
		}
		cout << (flag ? "Valid" : "Invalid") << endl;
	}
	return 0;
}
