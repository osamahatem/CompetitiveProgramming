/*
 * H. Kids Play.cpp
 *
 *  Created on: Oct 22, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;
const int LOGN = 30;

int up[MAXN], down[MAXN], par[LOGN][MAXN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		up[x] = i, down[i] = y;
	}
	for (int i = 1; i <= n; i++)
		par[0][i] = up[down[i]];
	for (int i = 1; i < LOGN; i++)
		for (int j = 1; j <= n; j++)
			par[i][j] = par[i - 1][par[i - 1][j]];
	while (k--) {
		int x, y;
		scanf("%d%d", &x, &y);
		for (int i = LOGN - 1; ~i; i--) {
			if (y >= (1 << i)) {
				x = par[i][x];
				y -= (1 << i);
			}
		}
		printf("%d\n", x);
	}
	return 0;
}
