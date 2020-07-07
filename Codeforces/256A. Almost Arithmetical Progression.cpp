/*
 * 256A. Almost Arithmetical Progression.cpp
 *
 *  Created on: Aug 30, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 4005;

int dp[MAXN][MAXN], arr[MAXN];
vector<int> rnk;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		rnk.push_back(arr[i]);
	}
	sort(rnk.begin(), rnk.end());
	rnk.erase(unique(rnk.begin(), rnk.end()), rnk.end());
	for (int i = 0; i < n; i++) {
		int r = lower_bound(rnk.begin(), rnk.end(), arr[i]) - rnk.begin();
		for (int j = 0; j < (int) rnk.size(); j++) {
			dp[j][r] = dp[r][j] + 1;
			ans = max(dp[j][r], ans);
		}
	}
	cout << ans << endl;
	return 0;
}
