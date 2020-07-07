/*
 * 12652 - Lines of Containers.cpp
 *
 *  Created on: Aug 16, 2014
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

	int r, c, grid[305][305], checkR[305][305], checkC[305][305], sw[305];
	while (cin >> r >> c) {
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				cin >> grid[i][j];
				checkR[i][j] = (grid[i][j] - 1) / c;
				checkC[i][j] = grid[i][j] - checkR[i][j] * c - 1;
			}
		}
		int s = 0;
		bool flag = 0;
		for (int i = 0; i < r; i++) {
			int x = checkR[i][0];
			for (int j = 0; j < c; j++)
				if (checkR[i][j] != x)
					flag = 1;
			sw[i] = x;
		}
		for (int i = 0; !flag && i < r; i++) {
			if (sw[i] != i) {
				s++;
				swap(sw[i], sw[sw[i]]);
				i--;
			}
		}
		for (int i = 0; i < c; i++) {
			int x = checkC[0][i];
			for (int j = 0; j < r; j++)
				if (checkC[j][i] != x)
					flag = 1;
			sw[i] = x;
		}
		for (int i = 0; !flag && i < c; i++) {
			if (sw[i] != i) {
				s++;
				swap(sw[i], sw[sw[i]]);
				i--;
			}
		}
		if (flag)
			cout << "*\n";
		else
			cout << s << "\n";
	}
	return 0;
}
