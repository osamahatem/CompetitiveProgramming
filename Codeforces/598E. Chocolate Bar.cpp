/*
 * 598E. Chocolate Bar.cpp
 *
 *  Created on: Nov 13, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int dp[31][31][51];

int solve(int h, int w, int k) {
	if (h * w == k || !k)
		return 0;
	if (h * w < k)
		return 1 << 28;
	if (h < w)
		swap(h, w);
	int &ret = dp[h][w][k];
	if (ret != -1)
		return ret;
	ret = 1 << 28;
	for (int i = 1; i < h; i++)
		for (int j = 0; j <= k; j++)
			ret = min(ret, w * w + solve(i, w, j) + solve(h - i, w, k - j));
	for (int i = 1; i < w; i++)
		for (int j = 0; j <= k; j++)
			ret = min(ret, h * h + solve(h, i, j) + solve(h, w - i, k - j));
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	memset(dp, -1, sizeof dp);
	int t, n, m, k;
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d%d", &n, &m, &k);
		printf("%d\n", solve(n, m, k));
	}
	return 0;
}
