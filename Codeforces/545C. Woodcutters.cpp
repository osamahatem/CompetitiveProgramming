/*
 * 545C. Woodcutters.cpp
 *
 *  Created on: May 19, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;

int n, x[MAXN], h[MAXN], dp[MAXN][2];

int solve(int idx, bool st) {
	if (idx == n - 1)
		return 2;
	int &ret = dp[idx][st];
	if (ret != -1)
		return ret;
	ret = solve(idx + 1, 0);
	if (!st && x[idx] - h[idx] > x[idx - 1])
		ret = max(ret, 1 + solve(idx + 1, 0));
	if (st && x[idx] - h[idx] > x[idx - 1] + h[idx - 1])
		ret = max(ret, 1 + solve(idx + 1, 0));
	if (x[idx] + h[idx] < x[idx + 1])
		ret = max(ret, 1 + solve(idx + 1, 1));
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> x[i] >> h[i];
	memset(dp, -1, sizeof dp);
	cout << (n < 3 ? n : solve(1, 0)) << endl;
	return 0;
}
