/*
 * 467C. George and Job.cpp
 *
 *  Created on: Aug 2, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

long long dp[2][5005], sum[5005];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, m, k, x;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		sum[i] = sum[i - 1] + x;
	}
	for (int kk = 1; kk <= k; kk++)
		for (int i = n; i; i--) {
			dp[kk % 2][i] = dp[kk % 2][i + 1];
			if (i + m - 1 <= n)
				dp[kk % 2][i] = max(dp[kk % 2][i],
						dp[(kk + 1) % 2][i + m] + sum[i + m - 1] - sum[i - 1]);
		}
	cout << dp[k % 2][1] << endl;
	return 0;
}
