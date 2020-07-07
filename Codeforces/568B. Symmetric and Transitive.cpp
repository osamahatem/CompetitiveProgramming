/*
 * 568B. Symmetric and Transitive.cpp
 *
 *  Created on: Aug 19, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 4005;
const int MOD = 1000000007;

int nCr[MAXN][MAXN], bell[MAXN];

long long fastPower(long long b, long long p) {
	long long ret = 1;
	for (; p; p >>= 1) {
		if (p & 1)
			ret = ret * b % MOD;
		b = b * b % MOD;
	}
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n;
	cin >> n;
	for (int i = 0; i <= n; i++) {
		nCr[i][0] = nCr[i][i] = 1;
		for (int j = 1; j < i; j++)
			nCr[i][j] = (nCr[i - 1][j - 1] + nCr[i - 1][j]) % MOD;
	}
	bell[0] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < i; j++)
			bell[i] = (bell[i] + (long long) nCr[i - 1][j] * bell[j]) % MOD;
	long long ans = 0;
	for (int i = 0; i < n; i++)
		ans = (ans + (long long) bell[i] * nCr[n][i]) % MOD;
	cout << ans << endl;
	return 0;
}
