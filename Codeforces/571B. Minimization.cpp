/*
 * 571B. Minimization.cpp
 *
 *  Created on: Aug 22, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 3e5 + 5;
const int MAXK = 5005;
const int INF = 2e9;

int n, k, arr[MAXN], len, cnt1, cnt2, dp[2][MAXK];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	len = n / k, cnt1 = n % k, cnt2 = k - n % k;
	sort(arr, arr + n);
	for (int t1 = cnt1; t1 >= 0; t1--)
		for (int t2 = cnt2; t2 >= 0; t2--) {
			int idx = (t1 + t2) * len + t1;
			dp[t1 & 1][t2] = (idx == n ? 0 : INF);
			if (t1 < cnt1)
				dp[t1 & 1][t2] = min(dp[t1 & 1][t2],
						dp[(t1 + 1) & 1][t2] + arr[idx + len] - arr[idx]);
			if (t2 < cnt2)
				dp[t1 & 1][t2] = min(dp[t1 & 1][t2],
						dp[t1 & 1][t2 + 1] + arr[idx + len - 1] - arr[idx]);
		}
	printf("%d\n", dp[0][0]);
	return 0;
}
