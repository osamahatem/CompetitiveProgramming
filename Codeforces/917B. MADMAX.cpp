/*
 * 917B. MADMAX.cpp
 *
 *  Created on: Jan 29, 2018
 *      Author: Osama Hatem
 */
 
/*
http://codeforces.com/blog/entry/57420
*/

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int dp[101][101][26];
vector<pair<int, char>> adj[101];

int solve(int i, int j, int last) {
	int &ret = dp[i][j][last];
	if (~ret)
		return ret;
	ret = 0;
	for (auto ch : adj[i]) {
		if (ch.second - 'a' >= last)
			ret |= 1 - solve(j, ch.first, ch.second - 'a');
	}
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

	memset(dp, -1, sizeof dp);
	int n, m;
	cin >> n >> m;
	while (m--) {
		int u, v;
		char c;
		cin >> u >> v >> c;
		adj[u].push_back(make_pair(v, c));
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			cout << "BA"[solve(i, j, 0)];
		cout << endl;
	}
	return 0;
}
