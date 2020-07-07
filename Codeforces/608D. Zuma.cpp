/*
 * 608D. Zuma.cpp
 *
 *  Created on: Dec 23, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int arr[505], dp[505][505];

int solve(int s, int e) {
	if (s == e || (e - s == 1 && arr[s] == arr[e]))
		return 1;
	int &ret = dp[s][e];
	if (ret != -1)
		return ret;
	ret = 1 << 28;
	if (arr[s] == arr[e])
		ret = solve(s + 1, e - 1);
	for (int i = s; i < e; i++)
		ret = min(ret, solve(s, i) + solve(i + 1, e));
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	memset(dp, -1, sizeof dp);
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	printf("%d\n", solve(0, n - 1));
	return 0;
}
