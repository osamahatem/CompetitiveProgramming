/*
 * 510D. Fox And Jumping.cpp
 *
 *  Created on: Feb 3, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int INF = 1 << 30;

int l[305], c[305], n;
map<int, int> dp[305];

int solve(int idx, int gcd) {
	if (gcd == 1)
		return 0;
	if (idx == n)
		return INF;
	if (dp[idx].count(gcd))
		return dp[idx][gcd];
	int ret = solve(idx + 1, gcd);
	ret = min(ret, c[idx] + solve(idx + 1, __gcd(gcd, l[idx])));
	return dp[idx][gcd] = ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> l[i];
	for (int i = 0; i < n; i++)
		cin >> c[i];
	int ans = solve(0, 0);
	cout << (ans >= INF ? -1 : ans) << endl;
	return 0;
}
