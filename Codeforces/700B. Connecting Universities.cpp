/*
 * 700B. Connecting Universities.cpp
 *
 *  Created on: Jul 22, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 2e5 + 5;

int n, k, sub[MAXN];
long long ans = 0;
bool uni[MAXN];
vector<int> adj[MAXN];

void dfs(int idx, int p) {
	sub[idx] += uni[idx];
	for (int i = 0; i < (int) adj[idx].size(); i++) {
		if (adj[idx][i] != p) {
			dfs(adj[idx][i], idx);
			sub[idx] += sub[adj[idx][i]];
			ans += min(2 * k - sub[adj[idx][i]], sub[adj[idx][i]]);
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif
	scanf("%d%d", &n, &k);
	for (int i = 0; i < 2 * k; i++) {
		int x;
		scanf("%d", &x);
		uni[x] = 1;
	}
	for (int i = 1; i < n; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1, -1);
	printf("%lld\n", ans);
	return 0;
}
