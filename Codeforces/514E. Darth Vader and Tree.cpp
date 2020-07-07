/*
 * 514E. Darth Vader and Tree.cpp
 *
 *  Created on: Aug 15, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MOD = 1000000007;

int cnt[105];
long long ans[105], mat[105][105];

void mat_mul(long long ma[105][105], long long mb[105][105]) {
	long long ret[105][105];
	for (int r = 0; r <= 100; r++)
		for (int c = 0; c <= 100; c++) {
			ret[r][c] = 0;
			for (int i = 0; i <= 100; i++)
				ret[r][c] = (ret[r][c] + ma[r][i] * mb[i][c]) % MOD;
		}
	memcpy(ma, ret, sizeof ret);
}

void mat_pow(long long mat[105][105], long long p) {
	long long ret[105][105];
	for (int r = 0; r <= 100; r++)
		for (int c = 0; c <= 100; c++)
			ret[r][c] = (r == c ? 1 : 0);
	for (; p; p >>= 1) {
		if (p & 1)
			mat_mul(ret, mat);
		mat_mul(mat, mat);
	}
	memcpy(mat, ret, sizeof ret);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, x, d;
	cin >> n >> x;
	for (int i = 0; i < n; i++) {
		cin >> d;
		cnt[d]++;
	}
	ans[0] = ans[1] = 1;
	mat[0][0] = mat[1][0] = 1;
	for (int i = 1; i <= 100; i++)
		mat[1][i] = cnt[i];
	for (int i = 2; i <= 100; i++)
		mat[i][i - 1] = 1;
	mat_pow(mat, x);
	long long ret = 0;
	for (int i = 0; i <= 100; i++)
		ret = (ret + mat[1][i] * ans[i]) % MOD;
	cout << ret << endl;
	return 0;
}
