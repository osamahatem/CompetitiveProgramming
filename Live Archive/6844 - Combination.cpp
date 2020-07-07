/*
 * 6844 - Combination.cpp
 *
 *  Created on: Oct 12, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

long long L, H, lim;
long long dp[42][42][2], sum[42];
bool one[42];

long long solve(int bit, int left, bool sm) {
	if (left < 0 || left - 1 > bit)
		return 0;
	if (bit < 0)
		return 1;
	long long &ret = dp[bit][left][sm];
	if (ret != -1)
		return ret;
	bool one = lim & (1ll << bit);
	ret = solve(bit - 1, left, sm || one);
	if (sm || one)
		ret += solve(bit - 1, left - 1, sm);
	return ret;
}

int len(long long x) {
	int ret = 0;
	while (x) {
		ret++;
		x >>= 1;
	}
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	while (scanf("%lld%lld", &L, &H), H) {
		unsigned long long ans = 0;
		lim = H;
		int llen = len(lim);
		for (int i = 0; i <= llen; i++)
			memset(dp[i], -1, sizeof dp[i]);
		for (int i = 0; i <= llen; i++)
			sum[i] = solve(llen - 1, i, 0);
		if (L) {
			lim = L - 1;
			llen = len(lim);
			for (int i = 0; i <= llen; i++)
				memset(dp[i], -1, sizeof dp[i]);
			for (int i = 0; i <= llen; i++)
				sum[i] -= solve(llen - 1, i, 0);
		}
		unsigned long long p = 1;
		llen = len(H);
		for (int i = 0; i <= llen; i++) {
			ans += p * sum[i];
			p *= 2;
		}
		printf("%llu\n", ans);
	}
	return 0;
}
