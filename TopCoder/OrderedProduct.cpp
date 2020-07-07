/*
 * OrderedProduct.cpp
 *
 *  Created on: Mar 31, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

class OrderedProduct {
	static const int MAXN = 5e3 + 5;
	static const int MOD = 1e9 + 7;

	int nCr[MAXN][MAXN], dp[MAXN / 2];

	void init() {
		for (int i = 0; i < MAXN; i++) {
			nCr[i][0] = nCr[i][i] = 1;
			for (int j = 1; j < i; j++)
				nCr[i][j] = (nCr[i - 1][j - 1] + nCr[i - 1][j]) % MOD;
		}
	}
public:
	int count(vector<int> a) {
		init();
		int n = 0, ans = 0;
		for (int x : a)
			n += x;
		for (int i = 1; i <= n; i++) {
			dp[i] = 1;
			for (int x : a)
				dp[i] = 1ll * dp[i] * nCr[x + i - 1][x] % MOD;
			for (int j = 1; j < i; j++)
				dp[i] = (dp[i] - 1ll * dp[j] * nCr[i][j] % MOD) % MOD;
			ans = (ans + dp[i]) % MOD;
		}
		return (ans + MOD) % MOD;
	}
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	return 0;
}
