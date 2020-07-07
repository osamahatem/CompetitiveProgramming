/*
 * 401D. Roman and Numbers.cpp
 *
 *  Created on: Jul 18, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

long long dp[1 << 18][100];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	long long n;
	int m;
	cin >> n >> m;
	vector<int> digs;
	while (n) {
		digs.push_back(n % 10);
		n /= 10;
	}
	sort(digs.begin(), digs.end());
	int sz = digs.size();
	dp[(1 << sz) - 1][0] = 1;
	for (int mask = (1 << sz) - 2; mask >= 0; mask--)
		for (int mod = 0; mod < m; mod++) {
			int last = -1;
			for (int d = 0; d < sz; d++)
				if (!(mask & (1 << d)) && (mask || digs[d])
						&& (last == -1 || digs[d] != digs[last])) {
					int newMask = mask | (1 << d);
					int newMod = (mod * 10 + digs[d]) % m;
					dp[mask][mod] += dp[newMask][newMod];
					last = d;
				}
		}
	cout << dp[0][0] << endl;
	return 0;
}
