/*
 * PLUSMUL.cpp
 *
 *  Created on: Jun 3, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;

int arr[MAXN];

int fastPower(int b, int p) {
	p = max(p, 0);
	int ret = 1;
	for (; p; p >>= 1) {
		if (p & 1)
			ret = 1ll * ret * b % MOD;
		b = 1ll * b * b % MOD;
	}
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int T;
	scanf("%d", &T);
	while (T--) {
		int N, x, product = 0, ans = 0;
		scanf("%d", &N);
		for (int i = 0; i < N; i++)
			scanf("%d", &arr[i]);
		for (int i = 0; i < N; i++) {
			x = arr[i];
			product = 1ll * product * x % MOD;
			product = (1ll * product + 1ll * x * fastPower(2, i - 1)) % MOD;
			int temp = 1ll * product * fastPower(2, N - i - 2) % MOD;
			ans = (1ll * ans + temp) % MOD;
		}
		printf("%d\n", ans);
	}
	return 0;
}
