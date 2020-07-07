/*
 * 505C. Mr. Kitayuta, the Treasure Hunter.cpp
 *
 *  Created on: Jan 18, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int ISL = 30000;

int shift, dp[ISL + 1][505], gem[ISL + 1];

int solve(int n, int d) {
	if (n > ISL)
		return 0;
	int &ret = dp[n][d];
	if (ret != -1)
		return ret;
	ret = 0;
	int dist = d + shift;
	if (dist > 1)
		ret = max(ret, solve(n + dist - 1, d - 1));
	ret = max(ret, solve(n + dist, d));
	ret = max(ret, solve(n + dist + 1, d + 1));
	ret += gem[n];
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	memset(dp, -1, sizeof dp);
	memset(gem, 0, sizeof gem);
	int n, d, x;
	cin >> n >> d;
	while (n--) {
		cin >> x;
		gem[x]++;
	}
	int temp = d, cur = 0;
	while (temp > 0 && cur <= ISL) {
		cur += temp;
		temp--;
	}
	shift = d - temp;
	shift = d - shift;
	cout << solve(d, d - shift) << endl;
	return 0;
}
