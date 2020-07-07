/*
 * 553A. Kyoya and Colored Balls.cpp
 *
 *  Created on: Jun 24, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1005;
const int MOD = 1000000007;

long long nCr[MAXN][MAXN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	for (int i = 0; i < MAXN; i++) {
		nCr[i][0] = nCr[i][i] = 1;
		for (int j = 1; j < i; j++)
			nCr[i][j] = (nCr[i - 1][j] + nCr[i - 1][j - 1]) % MOD;
	}
	int k, x;
	long long sum = 0, ans = 1;
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> x;
		sum += x;
		ans = ans * nCr[sum - 1][--x] % MOD;
	}
	cout << ans << endl;
	return 0;
}
