/*
 * 466D. Increase Sequence.cpp
 *
 *  Created on: Jun 22, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MOD = 1000000007;
const int MAXN = 2005;

int arr[MAXN];
long long dp[2][MAXN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, h;
	cin >> n >> h;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	dp[n % 2][1] = dp[n % 2][0] = 1;
	for (int i = n - 1; i >= 0; i--)
		for (int j = 0; j < MAXN; j++) {
			if (arr[i] + j + 1 == h)
				dp[i % 2][j] = dp[(i + 1) % 2][j + 1];
			else if (arr[i] + j - 1 == h)
				dp[i % 2][j] = dp[(i + 1) % 2][j - 1] * j;
			else if (arr[i] + j == h)
				dp[i % 2][j] = dp[(i + 1) % 2][j] * (j + 1);
			else
				dp[i % 2][j] = 0;
			dp[i % 2][j] %= MOD;
		}
	cout << dp[0][0] << endl;
	return 0;
}
