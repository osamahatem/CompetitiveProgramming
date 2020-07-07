/*
 * E. Wooden Signs.cpp
 *
 *  Created on: Oct 1, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MOD = 2147483647;

int n, arr[2005];
long long dp[2005][2005];

int getOverlap(int s1, int e1, int s2, int e2) {
	if (s1 > e1)
		swap(s1, e1);
	if (s2 > e2)
		swap(s2, e2);
	return min(e1, e2) - max(s1, s2);
}

long long solve(int idx, int s, int e) {
	if (idx > n)
		return 1;
	long long &ret = dp[s][e];
	if (~ret)
		return ret;
	ret = 0;
	if (getOverlap(arr[idx], s, s, e) > 0)
		ret = (ret + solve(idx + 1, arr[idx], s)) % MOD;
	if (getOverlap(arr[idx], e, s, e) > 0)
		ret = (ret + solve(idx + 1, arr[idx], e)) % MOD;
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	memset(dp, -1, sizeof dp);
	scanf("%d", &n);
	for (int i = 0; i <= n; i++)
		scanf("%d", &arr[i]);
	printf("%lld\n", solve(2, arr[0], arr[1]));
	return 0;
}
