/*
 * 322D. Ciel and Duel.cpp
 *
 *  Created on: Jan 2, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

vector<int> atk, def, my;
int dp[101][101][101][2];

int solve(int m, int a, int d, bool flag) {
	if (m == (int) my.size()) {
		if (flag && (a < (int) atk.size() || d < (int) def.size()))
			return -(1 << 30);
		return 0;
	}
	int &ret = dp[m][a][d][flag];
	if (ret != -1)
		return ret;
	ret = max(solve(m + 1, a, d, flag), my[m] + solve(m + 1, a, d, 1));
	if (a < (int) atk.size() && my[m] >= atk[a])
		ret = max(ret, my[m] - atk[a] + solve(m + 1, a + 1, d, flag));
	if (d < (int) def.size() && my[m] > def[d])
		ret = max(ret, solve(m + 1, a, d + 1, flag));
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	memset(dp, -1, sizeof dp);
	int n, m, x;
	string t;
	cin >> n >> m;
	while (n--) {
		cin >> t >> x;
		if (t == "DEF")
			def.push_back(x);
		else
			atk.push_back(x);
	}
	while (m--) {
		cin >> x;
		my.push_back(x);
	}
	sort(atk.begin(), atk.end());
	sort(def.begin(), def.end());
	sort(my.begin(), my.end());
	cout << solve(0, 0, 0, 0) << endl;
	return 0;
}
