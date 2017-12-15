/*
 * 313D. Ilya and Roads.cpp
 *
 *  Created on: Feb 13, 2015
 *      Author: Osama Hatem
 */
 
/*
cost[i][j] represents the minimum cost needed to fix all holes between i and j,
inclusive, using one the of companies in the input. This array is
pre-calculated. Then we perform a straightforward O(n^3) dp to get the minimum
cost.
*/

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const long long INF = 1ll << 60;

int n;
long long dp[305][305], cost[305][305];

long long solve(int idx, int left) {
	if (left <= 0)
		return 0;
	if (idx > n)
		return INF;
	long long &ret = dp[idx][left];
	if (ret != -1)
		return ret;
	ret = solve(idx + 1, left);
	for (int i = idx; i <= n; i++)
		ret = min(ret, solve(i + 1, left - (i - idx + 1)) + cost[idx][i]);
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	memset(dp, -1, sizeof dp);
	int m, k, l, r, c;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
		fill(cost[i], cost[i] + n + 1, INF);
	for (int i = 0; i < m; i++) {
		cin >> l >> r >> c;
		for (int j = l; j <= r; j++)
			cost[j][r] = min(cost[j][r], (long long) c);
	}
	long long ans = solve(1, k);
	cout << (ans >= INF ? -1 : ans) << endl;
	return 0;
}
