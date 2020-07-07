/*
 * 6848 - Fishing.cpp
 *
 *  Created on: Oct 12, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int R, C, arr[105][105], mini[105][105][105], maxi[105][105][105];

pair<int, int> solve(int r, int c, int l) {
	if (!l)
		return make_pair(0, 0);
	if (r >= R || c >= C)
		return make_pair(1 << 29, -(1 << 29));
	if (mini[r][c][l] != -1)
		return make_pair(mini[r][c][l], maxi[r][c][l]);
	pair<int, int> temp = solve(r + 1, c, l);
	int mn = temp.first, mx = temp.second;
	temp = solve(r, c + 1, l);
	mn = min(mn, temp.first), mx = max(mx, temp.second);
	temp = solve(r + 1, c + 1, l - 1);
	mn = min(mn, temp.first + arr[r][c]), mx = max(mx, temp.second + arr[r][c]);
	return make_pair(mini[r][c][l] = mn, maxi[r][c][l] = mx);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int T;
	scanf("%d", &T);
	while (T--) {
		memset(mini, -1, sizeof mini);
		memset(maxi, -1, sizeof maxi);
		scanf("%d%d", &R, &C);
		for (int i = 0; i < R; i++)
			for (int j = 0; j < C; j++)
				scanf("%d", &arr[i][j]);
		int ans = 0;
		for (int i = 0; i <= min(R, C); i += 2) {
			int mn = solve(0, 0, i).first, mx = solve(0, 0, i / 2).second;
			ans = max(ans, mx - mn);
		}
		printf("%d\n", ans);
	}
	return 0;
}
