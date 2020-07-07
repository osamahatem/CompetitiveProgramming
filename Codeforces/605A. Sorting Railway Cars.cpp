/*
 * 605A. Sorting Railway Cars.cpp
 *
 *  Created on: Dec 9, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;

int N, arr[MAXN], dp[MAXN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	int ans = 0;
	for (int i = 0; i < N; i++) {
		dp[arr[i]] = 1 + dp[arr[i] - 1];
		ans = max(ans, dp[arr[i]]);
	}
	printf("%d\n", N - ans);
	return 0;
}
