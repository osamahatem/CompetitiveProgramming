/*
 * A. Fresh Chocolate.cpp
 *
 *  Created on: May 13, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int n, p, g, mod[4];
int dp[105][105][105][4];

int getLeft(int lft, int nxt) {
	if (lft >= nxt)
		return lft - nxt;
	nxt -= lft;
	return p - nxt;
}

int solve(int idx, int m1, int m2, int m3, int lft) {
	if (idx == n)
		return 0;
	int &ret = dp[idx][m1][m2][lft];
	if (~ret)
		return ret;
	ret = 0;
	if (m1)
		ret = max(ret, solve(idx + 1, m1 - 1, m2, m3, getLeft(lft, 1)));
	if (m2)
		ret = max(ret, solve(idx + 1, m1, m2 - 1, m3, getLeft(lft, 2)));
	if (m3)
		ret = max(ret, solve(idx + 1, m1, m2, m3 - 1, getLeft(lft, 3)));
	ret += lft ? 0 : 1;
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif

	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		memset(mod, 0, sizeof mod);
		memset(dp, -1, sizeof dp);
		scanf("%d%d", &n, &p);
		while (n--) {
			scanf("%d", &g);
			mod[g % p]++;
		}
		n = 0;
		for (int i = 1; i < p; i++)
			n += mod[i];
		int ans = solve(0, mod[1], mod[2], mod[3], 0);
		ans += mod[0];
		printf("Case #%d: %d\n", t, ans);
	}
	return 0;
}
