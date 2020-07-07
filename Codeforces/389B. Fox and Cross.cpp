/*
 * 389B. Fox and Cross.cpp
 *
 *  Created on: Jun 13, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int n;
char grid[105][105];
bool vis[105][105];
int dx[] = { 0, 1, -1, 0, 0 }, dy[] = { 0, 0, 0, 1, -1 };

bool valid(int x, int y) {
	return x < n && x >= 0 && y < n && y >= 0 && !vis[x][y] && grid[x][y] == '#';
}

void update(int x, int y) {
	for (int i = 0; i < 5; i++)
		if (!valid(x + dx[i], y + dy[i]))
			return;
	for (int i = 0; i < 5; i++)
		vis[x + dx[i]][y + dy[i]] = 1;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> grid[i];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			update(i, j);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (grid[i][j] == '#' && !vis[i][j]) {
				printf("NO\n");
				return 0;
			}
	printf("YES\n");
	return 0;
}
