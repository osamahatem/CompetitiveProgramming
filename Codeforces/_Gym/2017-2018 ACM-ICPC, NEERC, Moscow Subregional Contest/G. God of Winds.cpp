/*
 * G. God of Winds.cpp
 *
 *  Created on: Nov 14, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

bool calc[505][505];
long long x[505][505];
int sol[2][505][505], n, m;
int dr[] = { 1, 0, -1, 0 }, dc[] = { 0, 1, 0, -1 };

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	scanf("%d%d", &n, &m);
	bool ans = true;
	for (int i = 0; ans && i < n; i++)
		for (int j = 0; ans && j < 2 * m; j++)
			scanf("%d", &sol[j & 1][i][j / 2]);
	calc[n - 1][m - 1] = 1, x[n - 1][m - 1] = 0;
	for (int i = n - 1; ~i && ans; i--) {
		for (int j = m - 1; ~j && ans; j--) {
			long long cur = x[i][j];
			int nr = (i - 1 + n) % n, nc = j;
			long long nxt = cur + sol[0][i][j];
			if (!calc[nr][nc])
				calc[nr][nc] = 1, x[nr][nc] = nxt;
			else if (x[nr][nc] != nxt)
				ans = false;
			nr = i, nc = (j - 1 + m) % m;
			nxt = cur - sol[1][i][j];
			if (!calc[nr][nc])
				calc[nr][nc] = 1, x[nr][nc] = nxt;
			else if (x[nr][nc] != nxt)
				ans = false;
		}
	}
	printf("%s\n", ans ? "Yes" : "No");
	return 0;
}
