/*
 * 300D. Painting Square.cpp
 *
 *  Created on: Dec 19, 2014
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const long long mod = 7340033;

long long dp[3][31][1005];

long long solve(int cnt, int h, int k) {
	if (!k)
		return 1;
	if (!h)
		return 0;
	if (cnt == 3)
		return solve(0, h - 1, k);
	long long &ret = dp[cnt][h][k];
	if (ret != -1)
		return ret;
	if (cnt == 0)
		k--;
	ret = 0;
	for (int i = 0; i <= k; i++)
		ret = (ret + solve(0, h - 1, i) * solve(cnt + 1, h, k - i)) % mod;
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	memset(dp, -1, sizeof dp);
	int q, n, k, h;
	cin >> q;
	while (q--) {
		cin >> n >> k;
		h = 0;
		while (n > 1 && (n & 1)) {
			h++;
			n >>= 1;
		}
		cout << solve(0, h, k) << endl;
	}
	return 0;
}
