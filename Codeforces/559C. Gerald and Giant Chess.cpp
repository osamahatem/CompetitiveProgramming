/*
 * 559C. Gerald and Giant Chess.cpp
 *
 *  Created on: Jul 22, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MOD = 1000000007;
const int MAXN = 2e5 + 5;

struct black {
	int r, c;
	long long val;

	const bool operator<(const black &b) const {
		if (r != b.r)
			return r > b.r;
		return c > b.c;
	}
} all[2005];

long long fact[MAXN], inv[MAXN];

long long fastPower(long long b, long long p) {
	long long ret = 1;
	for (; p; p /= 2) {
		if (p & 1)
			ret = ret * b % MOD;
		b = b * b % MOD;
	}
	return ret;
}

long long nCr(int n, int r) {
	long long ret = fact[n];
	long long div = inv[r] * inv[n - r] % MOD;
	return ret * div % MOD;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	fact[0] = inv[0] = 1;
	for (int i = 1; i < MAXN; i++) {
		fact[i] = fact[i - 1] * i % MOD;
		inv[i] = fastPower(fact[i], MOD - 2);
	}
	int h, w, n;
	cin >> h >> w >> n;
	long long ans = nCr(h + w - 2, h - 1);
	for (int i = 0; i < n; i++)
		cin >> all[i].r >> all[i].c;
	sort(all, all + n);
	for (int i = 0; i < n; i++) {
		all[i].val = nCr(h + w - all[i].r - all[i].c, h - all[i].r);
		for (int j = 0; j < i; j++) {
			if (all[j].c >= all[i].c) {
				long long temp = nCr(all[j].r + all[j].c - all[i].r - all[i].c,
						all[j].r - all[i].r);
				temp = all[j].val * temp % MOD;
				all[i].val = (all[i].val - temp + MOD) % MOD;
			}
		}
		long long temp = nCr(all[i].r + all[i].c - 2, all[i].r - 1);
		temp = temp * all[i].val % MOD;
		ans = (ans - temp + MOD) % MOD;
	}
	cout << ans << endl;
	return 0;
}
