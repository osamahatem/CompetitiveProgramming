/*
 * 462A. Appleman and Easy Task.cpp
 *
 *  Created on: Jun 16, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int n;
char grid[105][105];
int dr[] = { -1, 1, 0, 0 }, dc[] = { 0, 0, 1, -1 };

bool valid(int r, int c) {
	return r >= 0 && r < n && c >= 0 && c < n;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%s", grid[i]);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			int cnt = 0;
			for (int d = 0; d < 4; d++)
				if (valid(i + dr[d], j + dc[d]))
					cnt += grid[i + dr[d]][j + dc[d]] == 'o';
			if (cnt % 2) {
				printf("NO\n");
				return 0;
			}
		}
	printf("YES\n");
	return 0;
}
