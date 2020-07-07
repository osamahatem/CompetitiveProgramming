/*
 * D. Merge.cpp
 *
 *  Created on: May 4, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MOD = 1e9 + 7;

int dp[2005][2005][2];
int n, arr1[2005], arr2[2005], pos1[2005];
int eq[2005];

int solve(int a, int b, int flag) {
	if (a > n || b > n)
		return 0;
	if (a == n && b == n)
		return 1;
	int &ret = dp[a][b][flag];
	if (ret != -1)
		return ret;
	ret = 0;
	if (!flag) {
		ret = (ret + solve(a + 1, b, (arr1[a] != arr2[b] ? 0 : 1))) % MOD;
		if (arr1[a] != arr2[b])
			ret = (ret + solve(a, b + 1, 0)) % MOD;
	} else {
		int aa = pos1[arr2[b]];
		int e = eq[arr2[b]];
		ret = (ret + solve(a + 1, b, (a - aa == e ? 0 : 1))) % MOD;
		ret = (ret + solve(a, b + 1, (a - aa == 1 ? 0 : 1))) % MOD;
		if (a - aa == e)
			ret = (ret + solve(aa, b + e + 1, 0)) % MOD;
	}
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	memset(dp, -1, sizeof dp);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr1[i]);
		pos1[arr1[i]] = i;
	}
	for (int i = 0; i < n; i++)
		scanf("%d", &arr2[i]);
	for (int i = 0; i < n; i++) {
		int p = pos1[arr2[i]];
		for (int j = 0; j + p < n && arr1[j + p] == arr2[i + j]; j++)
			eq[arr2[i]]++;
	}
	printf("%d\n", solve(0, 0, 0));
	return 0;
}
