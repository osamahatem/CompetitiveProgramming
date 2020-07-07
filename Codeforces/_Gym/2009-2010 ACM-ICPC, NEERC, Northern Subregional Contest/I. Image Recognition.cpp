/*
 * I. Image Recognition.cpp
 *
 *  Created on: Oct 7, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int INF = 1 << 28;

int d, h, w;
char grid[11][11][11];
int dp[11][11][1 << 11];
string ans;

pair<int, int> split(int x, int y, int mask) {
	pair<int, int> ret = make_pair(0, 0);
	for (int i = 0; i < d; i++) {
		if (!(mask & (1 << i)))
			continue;
		if (grid[i][x][y] == 'W')
			ret.first |= 1 << i;
		else
			ret.second |= 1 << i;
	}
	return ret;
}

int solve(int x, int y, int mask) {
	if (mask == (mask & -mask))
		return 0;
	int &ret = dp[x][y][mask];
	if (~ret)
		return ret;
	ret = INF;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			pair<int, int> newMasks = split(i, j, mask);
			if (newMasks.first && newMasks.second)
				ret = min(ret,
						abs(i - x) + abs(j - y)
								+ max(solve(i, j, newMasks.first),
										solve(i, j, newMasks.second)));
		}
	}
	return ret;
}

void build(int x, int y, int mask) {
	if (mask == (mask & -mask)) {
		int idx = 0;
		while (!(mask & (1 << idx)))
			idx++;
		ans += '0' + idx;
		return;
	}
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			pair<int, int> newMasks = split(i, j, mask);
			if (!newMasks.first || !newMasks.second)
				continue;
			int cur = abs(i - x) + abs(j - y)
					+ max(solve(i, j, newMasks.first),
							solve(i, j, newMasks.second));
			if (cur != dp[x][y][mask])
				continue;
			int xx = x, yy = y;
			while (xx < i)
				ans += 'D', xx++;
			while (xx > i)
				ans += 'U', xx--;
			while (yy < j)
				ans += 'R', yy++;
			while (yy > j)
				ans += 'L', yy--;
			ans += "(";
			build(i, j, newMasks.first);
			ans += ":";
			build(i, j, newMasks.second);
			ans += ")";
			return;
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	freopen("image.in", "r", stdin);
	freopen("image.out", "w", stdout);

	memset(dp, -1, sizeof dp);
	scanf("%d%d%d", &d, &h, &w);
	for (int i = 0; i < d; i++)
		for (int j = 0; j < h; j++)
			scanf("%s", grid[i][j]);
	solve(0, 0, (1 << d) - 1);
	build(0, 0, (1 << d) - 1);
	printf("%s\n", ans.c_str());
	return 0;
}
