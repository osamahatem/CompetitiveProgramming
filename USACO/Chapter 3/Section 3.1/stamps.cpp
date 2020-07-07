/*
 ID: 19semse1
 PROG: stamps
 LANG: C++
 */
/*
 * stamps.cpp
 *
 *  Created on: Mar 16, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int dp[2000005];

int main() {
//#ifndef ONLINE_JUDGE
	freopen("stamps.in", "r", stdin);
	freopen("stamps.out", "w", stdout);
//#endif

	int k, n, arr[55], maxi = 0;
	cin >> k >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i], maxi = max(maxi, arr[i]);
	maxi *= k;
	int ans = maxi;
	dp[0] = 0;
	for (int i = 1; i <= maxi; i++)
		dp[i] = k + 5;
	for (int i = 1; i <= maxi; i++) {
		for (int j = 0; j < n; j++)
			if (arr[j] <= i)
				dp[i] = min(dp[i], dp[i - arr[j]] + 1);
		if (dp[i] > k) {
			ans = i - 1;
			break;
		}
	}
	cout << ans << endl;
	return 0;
}
