/*
 * H. Paint.cpp
 *
 *  Created on: Oct 11, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 2e5 + 5;

long long len, dp[MAXN];
int n;
pair<long long, long long> all[MAXN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	scanf("%lld%d", &len, &n);
	for (int i = 0; i < n; i++)
		scanf("%lld%lld", &all[i].first, &all[i].second);
	sort(all, all + n);
	dp[n] = 0;
	for (int i = n - 1; ~i; i--) {
		int idx = lower_bound(all, all + n, make_pair(all[i].second, 0ll))
				- all;
		dp[i] = max(dp[i + 1], all[i].second - all[i].first + 1 + dp[idx]);
	}
	printf("%lld\n", len - dp[0]);
	return 0;
}
