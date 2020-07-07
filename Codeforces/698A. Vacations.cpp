/*
 * 698A. Vacations.cpp
 *
 *  Created on: Jul 19, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int n, arr[100], dp[3][100];

int solve(int last, int idx) {
	if (idx == n)
		return 0;
	int &ret = dp[last][idx];
	if (ret != -1)
		return ret;
	ret = 1 + solve(0, idx + 1);
	if ((arr[idx] & 1) && last != 1)
		ret = min(ret, solve(1, idx + 1));
	if ((arr[idx] & 2) && last != 2)
		ret = min(ret, solve(2, idx + 1));
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	memset(dp, -1, sizeof dp);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	cout << solve(0, 0) << endl;
	return 0;
}
