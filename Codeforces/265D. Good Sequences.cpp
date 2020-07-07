/*
 * 265D. Good Sequences.cpp
 *
 *  Created on: Feb 28, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, a, ans = 0;
	map<int, int> dp;
	cin >> n;
	while (n--) {
		cin >> a;
		int temp = a, tans = 1;
		for (int i = 2; i * i <= temp; i++)
			while (temp % i == 0)
				tans = max(tans, dp[i] + 1), temp /= i;
		if (temp > 1)
			tans = max(tans, dp[temp] + 1);
		ans = max(ans, tans), temp = a;
		for (int i = 2; i * i <= temp; i++)
			while (temp % i == 0)
				dp[i] = max(tans, dp[i]), temp /= i;
		if (temp > 1)
			dp[temp] = max(tans, dp[temp]);
	}
	cout << ans << endl;
	return 0;
}
