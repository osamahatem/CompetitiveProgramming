/*
 * 12703 - Little Rakin.cpp
 *
 *  Created on: Aug 9, 2014
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int cnt[41][1005];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int t;
	scanf("%d", &t);
	while (t--) {
		memset(cnt, 0, sizeof cnt);
		int n, a, b;
		scanf("%d%d%d", &n, &a, &b);
		for (int i = 2; i * i <= a; i++) {
			while (a % i == 0) {
				cnt[0][i]++;
				a /= i;
			}
		}
		if (a > 1)
			cnt[0][a]++;
		for (int i = 2; i * i <= b; i++) {
			while (b % i == 0) {
				cnt[1][i]++;
				b /= i;
			}
		}
		if (b > 1)
			cnt[1][b]++;
		for (int i = 2; i <= n; i++)
			for (int c = 0; c <= 1000; c++)
				cnt[i][c] = cnt[i - 1][c] + cnt[i - 2][c];
		for (int i = 0; i <= 1000; i++)
			if (cnt[n][i])
				printf("%d %d\n", i, cnt[n][i]);
		printf("\n");
	}
	return 0;
}
