/*
 * B. Rank and File.cpp
 *
 *  Created on: Apr 16, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int grid[55][55];

int canBeRow(int r, vector<int> &temp) {
	for (int i = 0; i < (int) temp.size(); i++)
		if (grid[r][i] == -1)
			continue;
		else if (grid[r][i] < temp[i])
			return 2;
		else if (grid[r][i] > temp[i])
			return 0;
	return 1;
}

int canBeCol(int c, vector<int> &temp) {
	for (int i = 0; i < (int) temp.size(); i++)
		if (grid[i][c] == -1)
			continue;
		else if (grid[i][c] != temp[i])
			return 0;
	return 1;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif

	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		memset(grid, -1, sizeof grid);
		printf("Case #%d: ", t);
		int n;
		scanf("%d", &n);
		vector<vector<int>> all;
		for (int i = 0; i < 2 * n - 1; i++) {
			vector<int> temp(n);
			for (int j = 0; j < n; j++)
				scanf("%d", &temp[j]);
			all.push_back(temp);
		}
		sort(all.begin(), all.end());

		for (int i = 0; i < n; i++)
			grid[i][0] = all[0][i];
		int idx = 1, r = 0, c = 1;
		int rowMissing = -1, colMissing = -1;
		while (idx < 2 * n - 1) {
			if (canBeRow(r, all[idx]) == 1) {
				for (int i = 0; i < n; i++)
					grid[r][i] = all[idx][i];
				r++;
			} else if (canBeRow(r, all[idx]) == 2) {
				if (canBeCol(c, all[idx])) {
					for (int i = 0; i < n; i++)
						grid[i][c] = all[idx][i];
					c++;
				} else {
					rowMissing = r++;
					idx--;
				}
			} else {
				if (!canBeCol(c, all[idx]))
					colMissing = c++, idx--;
				else {
					for (int i = 0; i < n; i++)
						grid[i][c] = all[idx][i];
					c++;
				}
			}
			idx++;
		}
		cerr << rowMissing << " " << colMissing << endl;
		assert(rowMissing == -1 || colMissing == -1);
		if (rowMissing == colMissing)
			colMissing = n - 1;

		vector<int> ans(n);
		if (rowMissing != -1)
			for (int i = 0; i < n; i++)
				ans[i] = grid[rowMissing][i];
		else
			for (int i = 0; i < n; i++)
				ans[i] = grid[i][colMissing];

		for (int i = 0; i < n; i++) {
			if (i)
				printf(" ");
			printf("%d", ans[i]);
		}
		printf("\n");
	}
	return 0;
}
