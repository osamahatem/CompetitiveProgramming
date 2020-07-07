/*
 * E. Extremal Permutations.cpp
 *
 *  Created on: Oct 5, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e4 + 5;

int n, m, dp[MAXN], nCr[MAXN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	freopen("extremal.in", "r", stdin);
	freopen("extremal.out", "w", stdout);

	scanf("%d%d", &n, &m);
	dp[0] = 1, nCr[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < i; j += 2)
			dp[i] = (dp[i] + 1ll * dp[j] * dp[i - j - 1] % m * nCr[j] % m) % m;
		for (int j = i; j; j--)
			nCr[j] = (nCr[j] + nCr[j - 1]) % m;
	}
	if (n < 2)
		printf("%d\n", 1 % m);
	else
		printf("%d\n", dp[n] * 2 % m);
	return 0;
}
