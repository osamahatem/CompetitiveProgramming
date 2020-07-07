/*
 * 895D. String Mark.cpp
 *
 *  Created on: Dec 4, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e6 + 5;
const int MOD = 1e9 + 7;

int fact[MAXN], cnt[26], len;
char A[MAXN], B[MAXN];

int fastPower(int b, int p) {
	int ret = 1;
	for (; p; p >>= 1) {
		if (p & 1)
			ret = 1ll * ret * b % MOD;
		b = 1ll * b * b % MOD;
	}
	return ret;
}

int solve(char str[]) {
	int idx = 0, ret = 0;
	int temp = fact[len - 1];
	for (int i = 0; i < 26; i++)
		temp = 1ll * temp * fastPower(fact[cnt[i]], MOD - 2) % MOD;
	while (idx < len) {
		for (int i = str[idx] - 'a' + 1; i < 26; i++)
			ret = (ret + 1ll * temp * cnt[i]) % MOD;
		if (!cnt[str[idx] - 'a'])
			break;
		temp = 1ll * temp * cnt[str[idx] - 'a'] % MOD;
		temp = 1ll * temp * fastPower(len - idx - 1, MOD - 2) % MOD;
		cnt[str[idx++] - 'a']--;
	}
	if (idx == len)
		ret = (ret + 1) % MOD;
	while (idx)
		cnt[str[--idx] - 'a']++;
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	fact[0] = 1;
	for (int i = 1; i < MAXN; i++)
		fact[i] = 1ll * i * fact[i - 1] % MOD;
	scanf("%s%s", A, B);
	len = strlen(A);
	for (int i = 0; i < len; i++)
		cnt[A[i] - 'a']++;
	printf("%d\n", (solve(A) - solve(B) - 1 + MOD) % MOD);
	return 0;
}
