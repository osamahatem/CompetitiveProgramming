/*
 * 550C. Divisibility by Eight.cpp
 *
 *  Created on: Jun 4, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

bool dp[101][8];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	string in;
	cin >> in;
	dp[(int) in.size()][0] = 1;
	for (int i = (int) in.size() - 1; i >= 0; i--)
		for (int m = 0; m < 8; m++) {
			int nm = (m * 10 + in[i] - '0') % 8;
			dp[i][m] = dp[i + 1][m] || dp[i + 1][nm];
		}
	string ans;
	int m = 0;
	for (int i = 0; i < (int) in.size(); i++)
		if (dp[i + 1][(m * 10 + in[i] - '0') % 8]) {
			ans += in[i];
			m = (m * 10 + in[i] - '0') % 8;
		}
	if (ans.size())
		cout << "YES\n" << (ans[0] == '0' ? "0" : ans) << endl;
	else
		cout << "NO" << endl;
	return 0;
}
