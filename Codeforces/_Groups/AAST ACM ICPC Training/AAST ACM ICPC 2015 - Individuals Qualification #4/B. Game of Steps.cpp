/*
 * B. Game of Steps.cpp
 *
 *  Created on: Sep 15, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int n, s, dice[20];
bool dp[1 << 20][20], vis[1 << 20][20];

bool solve(int mask, int last) {
	bool ret = 0;
	if (!mask) {
		for (int i = 0; !ret && i < n; i++)
			ret |= !solve(mask | (1 << i), i);
		return ret;
	}
	if (vis[mask][last])
		return dp[mask][last];
	vis[mask][last] = 1;
	for (int i = 0; !ret && i < s; i++) {
		int nc = (last + dice[i]) % n;
		if (!(mask & (1 << nc)))
			ret |= !solve(mask | (1 << nc), nc);
	}
	return dp[mask][last] = ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	freopen("steps.in", "r", stdin);
	int T;
	cin >> T;
	while (T--) {
		memset(vis, 0, sizeof vis);
		cin >> n >> s;
		for (int i = 0; i < s; i++)
			cin >> dice[i];
		cout << (solve(0, 0) ? "Player 1 wins" : "Player 2 wins") << endl;
	}
	return 0;
}
