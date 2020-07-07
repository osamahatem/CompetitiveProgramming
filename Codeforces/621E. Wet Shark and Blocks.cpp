/*
 * 621E. Wet Shark and Blocks.cpp
 *
 *  Created on: Mar 7, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MOD = 1e9 + 7;

int x, temp[100][100], res[100][100], base[100][100], cnt[10];

void mul(int a[][100], int b[][100]) {
	for (int i = 0; i < x; i++)
		for (int j = 0; j < x; j++)
			temp[i][j] = 0;
	for (int i = 0; i < x; i++)
		for (int j = 0; j < x; j++)
			for (int k = 0; k < x; k++)
				temp[i][j] = (1ll * temp[i][j] + 1ll * a[i][k] * b[k][j]) % MOD;
	for (int i = 0; i < x; i++)
		for (int j = 0; j < x; j++)
			a[i][j] = temp[i][j];
}

void power(int b[][100], int p) {
	for (int i = 0; i < x; i++)
		for (int j = 0; j < x; j++)
			res[i][j] = (i == j ? 1 : 0);
	if (!p)
		return;
	for (; p; p >>= 1) {
		if (p & 1)
			mul(res, b);
		mul(b, b);
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, b, k, d;
	scanf("%d%d%d%d", &n, &b, &k, &x);
	for (int i = 0; i < n; i++) {
		scanf("%d", &d);
		cnt[d % x]++;
	}
	memset(base, 0, sizeof base);
	for (int i = 0; i < x; i++)
		for (int d = 0; d < 10; d++) {
			int r = (i * 10 + d) % x;
			base[r][i] += cnt[d];
		}
	power(base, b - 1);
	int ans = 0;
	for (int i = 0; i < 10; i++)
		ans = (1ll * ans + 1ll * res[k][i] * cnt[i]) % MOD;
	printf("%d\n", ans);
	return 0;
}
