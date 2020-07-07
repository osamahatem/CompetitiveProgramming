/*
 * 690D2. The Wall (medium).cpp
 *
 *  Created on: Jul 10, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MOD = 1000003;
const int MAXN = 5e5 + 5;

long long fact[MAXN], inv[MAXN];

long long fastPower(long long b, long long p) {
	long long ret = 1;
	for (; p; p >>= 1) {
		if (p & 1)
			ret = ret * b % MOD;
		b = b * b % MOD;
	}
	return ret;
}

void init() {
	fact[0] = 1, inv[0] = 1;
	for (int i = 1; i < MAXN; i++) {
		fact[i] = fact[i - 1] * i % MOD;
		inv[i] = fastPower(fact[i], MOD - 2);
	}
}

long long nCr(int n, int r) {
	return fact[n] * inv[r] * inv[n - r] % MOD;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	init();
	int n, c;
	cin >> n >> c;
	if (n > c)
		swap(n, c);
	long long ans = 0;
	for (int i = 1; i <= n; i++)
		ans = (ans + nCr(n, i) * nCr(c, i)) % MOD;
	cout << ans << endl;
	return 0;
}
