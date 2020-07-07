/*
 * E. The Bavarian Beer Party.cpp
 *
 *  Created on: Oct 11, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int arr[1000], dp[1005][1005];

int solve(int s, int e) {
	if (s >= e)
		return 0;
	int& ret = dp[s][e];
	if (~ret)
		return ret;
	for (int i = s + 1; i <= e; i += 2)
		ret = max(ret,
				solve(s + 1, i - 1) + solve(i + 1, e) + (arr[s] == arr[i]));
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int T;
	scanf("%d", &T);
	while (T--) {
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d", &arr[i]);
		memset(dp, -1, sizeof dp);
		printf("%d\n", solve(0, n - 1));
	}
	return 0;
}
