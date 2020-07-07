/*
 * 687C. The Values You Can Make.cpp
 *
 *  Created on: Jun 29, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int n, c[501];
bool dp[501][501][2];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int k;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &c[i]);
	dp[0][0][n & 1] = 1;
	for (int i = n - 1, ii = (n - 1) & 1; i >= 0; i--, ii ^= 1)
		for (int kk = 0; kk <= k; kk++)
			for (int x = 0; x <= kk; x++) {
				dp[kk][x][ii] = dp[kk][x][ii ^ 1];
				if (c[i] <= kk) {
					dp[kk][x][ii] |= dp[kk - c[i]][x][ii ^ 1];
					if (c[i] <= x)
						dp[kk][x][ii] |= dp[kk - c[i]][x - c[i]][ii ^ 1];
				}
			}
	vector<int> ans;
	for (int i = 0; i <= k; i++)
		if (dp[k][i][0])
			ans.push_back(i);
	printf("%d\n", ans.size());
	for (int i = 0; i < (int) ans.size(); i++) {
		if (i)
			printf(" ");
		printf("%d", ans[i]);
	}
	printf("\n");
	return 0;
}
