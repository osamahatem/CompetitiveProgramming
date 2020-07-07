/*
 * 461B. Appleman and Tree - Tutorial.cpp
 *
 *  Created on: Aug 16, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;
const int MOD = 1000000007;

int head[MAXN], to[2 * MAXN], nxt[2 * MAXN], last;
bool black[MAXN];
long long dp[MAXN][2];

void addEdge(int f, int t) {
	to[last] = t;
	nxt[last] = head[f];
	head[f] = last++;
}

void addBiEdge(int f, int t) {
	addEdge(f, t);
	addEdge(t, f);
}

void dfs(int n, int par) {
	dp[n][0] = 1;
	dp[n][1] = 0;
	for (int i = head[n]; i != -1; i = nxt[i]) {
		if (to[i] == par)
			continue;
		dfs(to[i], n);
		dp[n][1] = (dp[n][1] * dp[to[i]][0] + dp[n][0] * dp[to[i]][1]) % MOD;
		dp[n][0] = dp[n][0] * dp[to[i]][0] % MOD;
	}
	if (black[n])
		dp[n][1] = dp[n][0];
	else
		dp[n][0] = (dp[n][0] + dp[n][1]) % MOD;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	memset(head, -1, sizeof head);
	int n, p;
	cin >> n;
	for (int i = 1; i < n; i++) {
		cin >> p;
		addBiEdge(i, p);
	}
	for (int i = 0; i < n; i++)
		cin >> black[i];
	dfs(0, -1);
	cout << dp[0][1] << endl;
	return 0;
}
