/*
 * A. Auxiliary Project.cpp
 *
 *  Created on: Nov 11, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e6 + 5;
const int INF = 1 << 24;

int dp[MAXN], cnt[] = { 6, 2, 5, 5, 4, 5, 6, 3, 7, 6 };

int solve(int n) {
	if (n < 0)
		return -INF;
	if (n == 0)
		return 0;
	int &ret = dp[n];
	if (~ret)
		return ret;
	ret = -INF;
	for (int i = 0; i < 10; ++i)
		ret = max(ret, i + solve(n - cnt[i]));
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	freopen("auxiliary.in", "r", stdin);
	freopen("auxiliary.out", "w", stdout);
	memset(dp, -1, sizeof dp);
	int n;
	cin >> n;
	cout << solve(n) << endl;
	return 0;
}
