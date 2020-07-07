/*
 * 283C. Coin Troubles.cpp
 *
 *  Created on: Sep 16, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MOD = 1e9 + 7;

int n, q, t, to[301], deg[301];
int vis[301], chain[301], id, cur;
int val[301], ordered[301];
long long inc[301];
int dp[2][100001];

bool DFS(int x) {
	vis[x] = chain[x] = id;
	ordered[++cur] = x;
	inc[x] = val[x];
	if (vis[to[x]])
		return false;
	if (to[x]) {
		bool ret = DFS(to[x]);
		inc[x] += inc[to[x]];
		return ret;
	}
	return true;
}

void NO() {
	printf("0\n");
	exit(0);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	scanf("%d%d%d", &n, &q, &t);
	for (int i = 1; i <= n; i++)
		scanf("%d", &val[i]);
	while (q--) {
		int u, v;
		scanf("%d%d", &u, &v);
		deg[u]++;
		to[v] = u;
	}
	for (int i = 1; i <= n; i++) {
		if (!deg[i]) {
			id++;
			if (!DFS(i))
				NO();
		}
	}
	for (int i = 1; i <= n; i++)
		if (!vis[i] && deg[i])
			NO();
	for (int i = 2; i <= n; i++)
		if (chain[ordered[i]] == chain[ordered[i - 1]]) {
			if (inc[ordered[i]] <= t)
				t -= inc[ordered[i]];
			else
				NO();
		}
	dp[(n + 1) & 1][0] = 1;
	for (int c = n & 1, cc = n; cc; c ^= 1, cc--) {
		for (int sum = 0; sum <= t; sum++) {
			dp[c][sum] = dp[c ^ 1][sum];
			long long ssum = inc[ordered[cc]];
			if (ssum <= sum)
				dp[c][sum] = (dp[c][sum] + dp[c][sum - ssum]) % MOD;
		}
	}
	printf("%d\n", dp[1][t]);
	return 0;
}
