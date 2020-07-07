/*
 * 12486 - Space Elevator.cpp
 *
 *  Created on: Aug 24, 2014
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

long long n, dp[20][2];

long long count(int idx, bool one) {
	if (idx < 0)
		return 1;
	long long &ret = dp[idx][one];
	if (ret != -1)
		return ret;
	ret = 0;
	for (int i = 0; i < 10; i++) {
		if (i == 4 || (one && i == 3))
			continue;
		ret += count(idx - 1, i == 1);
	}
	return ret;
}

void solve(int idx, bool one, bool trail) {
	if (idx < 0)
		return;
	for (int i = 0; i < 10; i++) {
		if (i == 4 || (one && i == 3))
			continue;
		long long temp = count(idx - 1, i == 1);
		if (temp > n) {
			if (trail || i)
				cout << i;
			solve(idx - 1, i == 1, trail || i != 0);
			return;
		} else
			n -= temp;
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	memset(dp, -1, sizeof dp);
	while (cin >> n) {
		solve(18, 0, 0);
		cout << "\n";
	}
	return 0;
}
