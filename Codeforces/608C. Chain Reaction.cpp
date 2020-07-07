/*
 * 608C. Chain Reaction.cpp
 *
 *  Created on: Dec 23, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;

pair<int, int> arr[MAXN];
int dp[MAXN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d%d", &arr[i].first, &arr[i].second);
	sort(arr + 1, arr + n + 1);
	int ans = 1 << 28;
	for (int i = 1; i <= n; i++) {
		int d = arr[i].first, p = arr[i].second;
		int pr = lower_bound(arr + 1, arr + 1 + n, make_pair(d - p, 0)) - arr
				- 1;
		dp[i] = dp[pr] + i - pr - 1;
		ans = min(ans, dp[i] + n - i);
	}
	printf("%d\n", ans);
	return 0;
}
