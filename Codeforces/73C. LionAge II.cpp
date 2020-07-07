/*
 * 73C. LionAge II.cpp
 *
 *  Created on: Aug 5, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int dp[105][105][26], bon[26][26];
string S;

int solve(int idx, int k, int last) {
	if (k < 0)
		return -(1 << 25);
	if (idx == (int) S.size())
		return 0;
	int &ret = dp[idx][k][last];
	if (ret != -1)
		return ret;
	ret = -(1 << 25);
	for (int i = 0; i < 26; i++) {
		int nbon = (idx ? bon[last][i] : 0);
		ret = max(ret, nbon + solve(idx + 1, k - (S[idx] - 'a' != i), i));
	}
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	memset(dp, -1, sizeof dp);
	int n, k;
	cin >> S >> k >> n;
	while (n--) {
		char a, b;
		cin >> a >> b;
		cin >> bon[a - 'a'][b - 'a'];
	}
	cout << solve(0, k, 0) << endl;
	return 0;
}
