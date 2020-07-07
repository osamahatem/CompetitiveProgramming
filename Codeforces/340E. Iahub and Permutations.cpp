/*
 * 340E. Iahub and Permutations.cpp
 *
 *  Created on: Feb 4, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MOD = 1000000007;

bool missing[2005], found[2005];
long long dp[2005][2005];

long long solve(int f, int l) {
	if (f == 1 && l == 0)
		return 1;
	long long &ret = dp[f][l];
	if (ret != -1)
		return ret;
	if (l == 0)
		return ret = f * solve(f - 1, l) % MOD;
	if (l == 1)
		return ret = f * solve(f, l - 1) % MOD;
	ret = f * solve(f, l - 1) % MOD;
	ret = (ret + (l - 1) * solve(f + 1, l - 2)) % MOD;
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	memset(dp, -1, sizeof dp);
	int n, x, f = 0, l = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		if (x == -1)
			missing[i] = 1;
		else
			found[x] = 1;
	}
	for (int i = 1; i <= n; i++)
		if (missing[i] && !found[i])
			l++;
		else if (!found[i])
			f++;
	cout << solve(f, l) << endl;
	return 0;
}
