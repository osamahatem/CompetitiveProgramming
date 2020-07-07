/*
 * D. Little thief Shi.cpp
 *
 *  Created on: Aug 30, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e6 + 5;

int val[MAXN], dp[MAXN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &val[i]);
	for (int i = n - 1; i >= 0; i--)
		dp[i] = max(dp[i + 1], val[i] + dp[i + 3]);
	printf("%d\n", dp[0]);
	return 0;
}
