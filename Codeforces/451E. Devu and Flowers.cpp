/*
 * 451E. Devu and Flowers.cpp
 *
 *  Created on: Aug 17, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MOD = 1e9 + 7;

int n;
long long s, f[20], fact_inv;

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
	fact_inv = 1;
	for (int i = 1; i < n; i++)
		fact_inv = fact_inv * i % MOD;
	fact_inv = fastPower(fact_inv, MOD - 2);
}

long long nCr(long long n, long long r) {
	long long ret = 1;
	for (int i = 0; i < r; i++)
		ret = ret * ((n - i) % MOD) % MOD;
	ret = ret * fact_inv % MOD;
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	long long sum = 0;
	cin >> n >> s;
	init();
	for (int i = 0; i < n; i++) {
		cin >> f[i];
		sum += f[i];
	}
	if (sum < s) {
		printf("0\n");
		return 0;
	}
	int ans = nCr(s + n - 1, n - 1);
	for (int i = 1; i < (1 << n); i++) {
		int boxes = 0;
		long long ss = s;
		for (int j = 0; j < n; j++)
			if (i & (1 << j))
				ss -= f[j] + 1, boxes++;
		if (ss < 0)
			continue;
		int temp = nCr(ss + n - 1, n - 1);
		if (boxes & 1)
			ans = (ans - temp + MOD) % MOD;
		else
			ans = (ans + temp) % MOD;
	}
	cout << ans << endl;
	return 0;
}
