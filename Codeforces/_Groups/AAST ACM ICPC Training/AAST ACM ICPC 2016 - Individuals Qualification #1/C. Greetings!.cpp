/*
 * C. Greetings!.cpp
 *
 *  Created on: Aug 29, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int n, k, w[15], h[15], q[15];
long long waste[1 << 15], dp[2][1 << 15];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> w[i] >> h[i] >> q[i];
	for (int i = 0; i < (1 << n); i++) {
		int mw = 0, mh = 0, tq = 0;
		long long area = 0;
		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) {
				mw = max(mw, w[j]);
				mh = max(mh, h[j]);
				area += 1ll * w[j] * h[j] * q[j];
				tq += q[j];
			}
		}
		waste[i] = 1ll * mw * mh * tq - area;
	}
	memset(dp[0], 127, sizeof dp[0]);
	dp[0][0] = 0;
	for (int kk = 1, kkk = 1; kk <= k; kk++, kkk ^= 1) {
		for (int mask = 1; mask < (1 << n); mask++) {
			dp[kkk][mask] = 1ll << 60;
			for (int submask = mask; submask; submask = (submask - 1) & mask) {
				dp[kkk][mask] = min(dp[kkk][mask],
						waste[submask] + dp[kkk ^ 1][mask - submask]);
			}
		}
	}
	cout << dp[k & 1][(1 << n) - 1] << endl;
	return 0;
}
