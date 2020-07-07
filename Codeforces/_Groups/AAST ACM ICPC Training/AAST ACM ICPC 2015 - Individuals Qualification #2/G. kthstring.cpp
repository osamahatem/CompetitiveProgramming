/*
 * G. kthstring.cpp
 *
 *  Created on: Sep 7, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

long long dp[45][30];
string ans;

long long cnt(int idx, int last) {
	if (!idx || last == 25)
		return 1;
	long long &ret = dp[idx][last];
	if (ret != -1)
		return ret;
	ret = 0;
	for (int i = last; i < 26; i++)
		ret += cnt(idx - 1, i);
	return ret;
}

void solve(int idx, int last, long long k) {
	if (!idx)
		return;
	for (int i = last; i < 26; i++) {
		long long t = cnt(idx - 1, i);
		if (t < k)
			k -= t;
		else {
			ans += 'a' + i;
			solve(idx - 1, i, k);
			return;
		}
	}
	ans = "NO SOLUTION";
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	freopen("kthstring.in", "r", stdin);
	memset(dp, -1, sizeof dp);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		int n;
		long long k;
		ans.clear();
		cin >> n >> k;
		solve(n, 0, k);
		cout << "Case " << t << ": " << ans << endl;
	}
	return 0;
}
