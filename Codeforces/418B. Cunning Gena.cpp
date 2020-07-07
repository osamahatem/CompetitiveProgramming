/*
 * 418B. Cunning Gena.cpp
 *
 *  Created on: Jul 18, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAX_MASK = 1 << 20;
const long long INF = 1ll << 62;

struct frnd {
	int x, k, m;

	const bool operator <(const frnd &a) const {
		return k < a.k;
	}
} frnds[105];

long long dp[MAX_MASK];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	fill(dp, dp + MAX_MASK, INF);
	int n, m, b;
	cin >> n >> m >> b;
	for (int i = 0; i < n; i++) {
		int np, p;
		cin >> frnds[i].x >> frnds[i].k >> np;
		frnds[i].m = 0;
		while (np--) {
			cin >> p;
			frnds[i].m |= 1 << --p;
		}
	}
	sort(frnds, frnds + n);
	dp[(1 << m) - 1] = 0;
	for (int f = 0; f < n; f++)
		for (int i = (1 << m) - 2; i >= 0; i--) {
			int newMask = i | frnds[f].m;
			long long cost = frnds[f].x + (long long) b * frnds[f].k * !i;
			dp[i] = min(dp[i], cost + dp[newMask]);
		}
	cout << (dp[0] == INF ? -1 : dp[0]) << endl;
	return 0;
}
