/*
 * 12442 - Forwarding Emails.cpp
 *
 *  Created on: Sep 10, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 5e4 + 5;

int n, to[MAXN], dp[MAXN], vis[MAXN], cycle_root;
bool cycle;

int solve(int x, int cnt) {
	vis[x] = 1;
	if (vis[to[x]] == 1)
		cycle = 1, cycle_root = to[x], dp[x] = cnt;
	else if (vis[to[x]] == 2)
		dp[x] = 1 + dp[to[x]];
	else {
		solve(to[x], cnt + 1);
		if (cycle)
			dp[x] = dp[to[x]];
		else
			dp[x] = 1 + dp[to[x]];
		if (x == cycle_root)
			cycle = 0;
	}
	vis[x] = 2;
	return dp[x];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		memset(vis, 0, sizeof vis);
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			int u, v;
			scanf("%d%d", &u, &v);
			to[u] = v;
		}
		int maxi = 0, ans = -1;
		for (int i = 1; i <= n; i++) {
			if (!vis[i] && solve(i, 1) > maxi)
				maxi = dp[i], ans = i;
		}
		printf("Case %d: %d\n", t, ans);
	}
	return 0;
}
