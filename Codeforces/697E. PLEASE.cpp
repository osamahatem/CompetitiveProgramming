/*
 * 697E. PLEASE.cpp
 *
 *  Created on: Jul 14, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MOD = 1e9 + 7;

void mul(long long a[2][2], long long b[2][2]) {
	long long temp[2][2];
	memset(temp, 0, sizeof temp);
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			for (int k = 0; k < 2; k++)
				temp[i][j] = (temp[i][j] + a[i][k] * b[k][j]) % MOD;
	memcpy(a, temp, sizeof temp);
}

void mat_pow(long long mat[2][2], long long p) {
	long long temp[2][2];
	memset(temp, 0, sizeof temp);
	temp[0][0] = temp[1][1] = 1;
	for (; p; p >>= 1) {
		if (p & 1)
			mul(temp, mat);
		mul(mat, mat);
	}
	memcpy(mat, temp, sizeof temp);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int k;
	long long all = 1, a;
	long long res[2][2] = { { MOD - 1, 1 }, { 0, 2 } };
	scanf("%d", &k);
	while (k--) {
		scanf("%lld", &a);
		a %= MOD - 1;
		all = all * a % (MOD - 1);
	}
	long long temp[2][2] = { { 0, 500000004 }, { 0, 500000004 } };
	mat_pow(res, all);
	mul(res, temp);
	printf("%lld/%lld\n", res[0][1], res[1][1]);
	return 0;
}
