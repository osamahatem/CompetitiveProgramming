/*
 * 35B. Warehouse.cpp
 *
 *  Created on: Oct 14, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int n, m, q;
string grid[31][31];
char buff[15];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d%d%d", &n, &m, &q);
	int x, y;
	while (q--) {
		scanf("%s", buff);
		if (buff[0] == '+') {
			scanf("%d%d%s", &x, &y, buff);
			bool put = 0;
			for (int i = x; !put && i <= n; i++)
				for (int j = (i == x ? y : 1); !put && j <= m; j++)
					if (grid[i][j].empty())
						grid[i][j] = buff, put = 1;
		} else {
			scanf("%s", buff);
			x = -1, y = -1;
			for (int i = 1; x == -1 && i <= n; i++)
				for (int j = 1; x == -1 && j <= m; j++)
					if (grid[i][j] == buff)
						grid[i][j].clear(), x = i, y = j;
			printf("%d %d\n", x, y);
		}
	}
	return 0;
}
