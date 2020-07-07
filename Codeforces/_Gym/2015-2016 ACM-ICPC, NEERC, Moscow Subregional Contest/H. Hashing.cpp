/*
 * H. Hashing.cpp
 *
 *  Created on: Sep 28, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;
const int LIM = 256;

int n, ans, arr[MAXN];
long long dp[2][LIM];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%x", &arr[i]);
	for (int i = (n - 1) & 1, ii = n - 1; ii >= 0; ii--, i ^= 1) {
		for (int j = 0; j < LIM && j <= ii; j++) {
			dp[i][j] = dp[i ^ 1][j] + ((ii - j) ^ arr[ii]);
			if (j + 1 < LIM)
				dp[i][j] = max(dp[i][j], dp[i ^ 1][j + 1]);
		}
	}
	printf("%lld\n", dp[0][0]);
	return 0;
}
