/*
 * 4482 - Klingon Levels.cpp
 *
 *  Created on: Sep 21, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int acum[10005][1005];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, k, x;
	while (scanf("%d", &n), n) {
		int ans = 0;
		for (int i = 0; i < n; i++) {
			memset(acum[i], 0, sizeof acum[i]);
			scanf("%d", &k);
			ans += k;
			while (k--) {
				scanf("%d", &x);
				acum[i][x]++;
			}
			for (int j = 1; j <= 1000; j++)
				acum[i][j] += acum[i][j - 1];
		}
		for (int i = 1; i <= 1000; i++) {
			int temp = 0;
			for (int j = 0; j < n; j++)
				temp += abs(acum[j][1000] - 2 * acum[j][i - 1]);
			ans = min(ans, temp);
		}
		printf("%d\n", ans);
	}
	return 0;
}
