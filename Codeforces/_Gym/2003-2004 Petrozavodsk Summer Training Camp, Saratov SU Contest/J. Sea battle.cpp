/*
 * J. Sea battle.cpp
 *
 *  Created on: May 1, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

char grid[15][15];
int cnt[5];

int check(int i, int j) {
	bool ver = 0, hor = 0;
	if ((i && grid[i - 1][j] == '*') || (i < 9 && grid[i + 1][j] == '*'))
		ver = 1;
	if ((j && grid[i][j - 1] == '*') || (j < 9 && grid[i][j + 1] == '*'))
		hor = 1;
	for (int x = -1; x <= 1; x += 2)
		for (int y = -1; y <= 1; y += 2)
			if (i + x >= 0 && i + x < 10 && j + y >= 0 && j + y < 10
					&& grid[i + x][j + y] == '*')
				return 0;
	if (hor == ver)
		return !hor;
	int ret = 1;
	for (int x = i - 1; x >= 0 && grid[x][j] == '*'; x--)
		ret++;
	for (int x = i + 1; x < 10 && grid[x][j] == '*'; x++)
		ret++;
	for (int x = j - 1; x >= 0 && grid[i][x] == '*'; x--)
		ret++;
	for (int x = j + 1; x < 10 && grid[i][x] == '*'; x++)
		ret++;
	if (ret > 4)
		return 0;
	return ret;
}

int main() {
//#ifndef ONLINE_JUDGE
	freopen("sea.in", "r", stdin);
	freopen("sea.out", "w", stdout);
//#endif

	int n;
	scanf("%d", &n);
	while (n--) {
		cnt[0] = 0, cnt[1] = 4, cnt[2] = 6, cnt[3] = 6, cnt[4] = 4;
		for (int i = 0; i < 10; i++)
			scanf("%s", grid[i]);
		for (int i = 0; i < 10; i++)
			for (int j = 0; j < 10; j++)
				if (grid[i][j] == '*')
					cnt[check(i, j)]--;
		int x = 0;
		for (int i = 0; i < 5; i++)
			x += abs(cnt[i]);
		if (x)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}
