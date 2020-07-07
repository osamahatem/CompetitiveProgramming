/*
 * 785D. Anton and School - 2.cpp
 *
 *  Created on: Mar 21, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 5;

int fact[MAXN];
char in[MAXN];

void init() {
	fact[0] = 1;
	for (int i = 1; i < MAXN; i++)
		fact[i] = 1ll * fact[i - 1] * i % MOD;
}

int fastPower(int b, int p) {
	int ret = 1;
	for (; p; p >>= 1) {
		if (p & 1)
			ret = 1ll * ret * b % MOD;
		b = 1ll * b * b % MOD;
	}
	return ret;
}

inline int inverse(int x) {
	return fastPower(x, MOD - 2);
}

int nCr(int n, int r) {
	int ret = fact[n];
	ret = 1ll * ret * inverse(fact[r]) % MOD;
	ret = 1ll * ret * inverse(fact[n - r]) % MOD;
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	init();
	scanf("%s", in);
	int len = strlen(in);
	int op = 0, cl = count(in, in + len, ')'), ans = 0;
	for (int i = 0; i < len && cl; i++) {
		if (in[i] == '(') {
			op++;
			ans = (ans + nCr(op + cl - 1, op)) % MOD;
		} else {
			cl--;
		}
	}
	printf("%d\n", ans);
	return 0;
}
