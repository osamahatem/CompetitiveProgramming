/*
 * C. Carpet.cpp
 *
 *  Created on: Nov 14, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;

vector<int> adj[MAXN];
int sz[MAXN], sc[MAXN], n;
pair<int, int> ans[MAXN];

void dfs(int idx, int par) {
	sz[idx]++, sc[idx] = -1;
	int maxi = -1;
	for (int ch : adj[idx]) {
		if (ch == par)
			continue;
		dfs(ch, idx);
		sz[idx] += sz[ch];
		if (sz[ch] > maxi)
			maxi = sz[ch], sc[idx] = ch;
	}
}

void solve(int idx, int par, int r, int c) {
	ans[idx] = make_pair(r, c);
	int temp = 1;
	for (int ch : adj[idx]) {
		if (ch == par || ch == sc[idx])
			continue;
		solve(ch, idx, r + 1, c + temp);
		temp += sz[ch];
	}
	if (~sc[idx])
		solve(sc[idx], idx, r, c + temp);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1, 0);
	solve(1, 0, 1, 1);
	for (int i = 1; i <= n; i++)
		printf("%d %d\n", ans[i].second, ans[i].first);
	return 0;
}
