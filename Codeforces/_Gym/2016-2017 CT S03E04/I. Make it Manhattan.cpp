/*
 * I. Make it Manhattan.cpp
 *
 *  Created on: Oct 11, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1005;

int row[MAXN], col[MAXN], common[MAXN * MAXN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int T;
	scanf("%d", &T);
	while (T--) {
		int n, d;
		scanf("%d%d", &d, &n);
		memset(row, 0, d * sizeof row[0]);
		memset(col, 0, d * sizeof col[0]);
		memset(common, 0, d * d * sizeof common[0]);
		int ans = n;
		while (n--) {
			int x, y;
			scanf("%d%d", &x, &y);
			x = ((x % d) + d) % d;
			y = ((y % d) + d) % d;
			row[x]++, col[y]++, common[x * d + y]++;
		}
		for (int i = 0; i < d; i++)
			for (int j = 0; j < d; j++)
				ans = min(ans, row[i] + col[j] - common[i * d + j]);
		printf("%d\n", ans);
	}
	return 0;
}
