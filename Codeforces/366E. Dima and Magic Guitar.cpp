/*
 * 366E. Dima and Magic Guitar.cpp
 *
 *  Created on: Jul 25, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int n, m, k, s, best[10][4];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int x, last, ans = 0;
	memset(best, -128, sizeof best);
	scanf("%d%d%d%d", &n, &m, &k, &s);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			scanf("%d", &x);
			best[x][0] = max(best[x][0], i + j);
			best[x][1] = max(best[x][1], i - j);
			best[x][2] = max(best[x][2], -i + j);
			best[x][3] = max(best[x][3], -i - j);
		}
	scanf("%d", &last);
	for (int i = 1; i < s; i++) {
		scanf("%d", &x);
		for (int i = 0; i < 4; i++)
			ans = max(ans, best[last][i] + best[x][3 - i]);
		last = x;
	}
	printf("%d\n", ans);
	return 0;
}
