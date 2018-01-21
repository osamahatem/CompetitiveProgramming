/*
 * 914C. Travelling Salesman and Special Numbers.cpp
 *
 *  Created on: Jan 20, 2018
 *      Author: Osama Hatem
 */
 
/*
http://codeforces.com/blog/entry/57250
*/

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MOD = 1e9 + 7;

string n;
int K, cnt[1005], dp[1005][1005][2];

int solve(int idx, int k, bool sm) {
	if (idx == (int) n.size())
		return k ? 0 : 1;
	int &ret = dp[idx][k][sm];
	if (~ret)
		return ret;
	ret = solve(idx + 1, k, sm || n[idx] == '1');
	if (k && (sm || n[idx] == '1'))
		ret = (ret + solve(idx + 1, k - 1, sm)) % MOD;
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cnt[1] = 0;
	for (int i = 2; i <= 1000; i++)
		cnt[i] = 1 + cnt[__builtin_popcount(i)];
	memset(dp, -1, sizeof dp);

	cin >> n >> K;
	int ans = 0;
	for (int i = 1; i <= (int) n.size(); i++)
		if (cnt[i] == K - 1)
			ans = (ans + solve(0, i, 0)) % MOD;
	if (K == 0)
		ans = 1;
	else if (K == 1)
		ans -= 1;
	cout << ans << endl;
	return 0;
}
