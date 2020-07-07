/*
 ID: 19semse1
 PROG: money
 LANG: C++
 */
/*
 * money.cpp
 *
 *  Created on: Mar 11, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

long long dp[10005];
int val[25];

int main() {
//#ifndef ONLINE_JUDGE
	freopen("money.in", "r", stdin);
	freopen("money.out", "w", stdout);
//#endif

	int v, n;
	cin >> v >> n;
	for (int i = 0; i < v; i++)
		cin >> val[i];
	dp[0] = 1;
	for (int j = 0; j < v; j++)
		for (int i = 0; i < n; i++)
			if (val[j] + i <= n)
				dp[val[j] + i] += dp[i];
	cout << dp[n] << endl;
	return 0;
}
