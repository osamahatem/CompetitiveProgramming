/*
 * 979C. Kuro and Walking Route.cpp
 *
 *  Created on: May 14, 2018
 *      Author: Osama Hatem
 */

/*
 * http://codeforces.com/blog/entry/59462
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 3e5 + 5;

int n, x, y;
vector<int> adj[MAXN];
int dep[MAXN], par[MAXN], sz[MAXN];

void dfs(int idx) {
	for (auto ch : adj[idx]) {
		if (ch == par[idx])
			continue;
		dep[ch] = dep[idx] + 1, par[ch] = idx;
		dfs(ch);
		sz[idx] += sz[ch];
	}
	sz[idx]++;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> x >> y;
	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	dfs(1);

	int last = -1, xx = x, yy = y;
	while (dep[x] > dep[y]) {
		last = x;
		x = par[x];
	}
	while (dep[y] > dep[x]) {
		last = y;
		y = par[y];
	}
	while (x != y)
		x = par[x], y = par[y];

	long long ans = 1ll * n * (n - 1);
	if (x != xx && x != yy)
		ans -= 1ll * sz[xx] * sz[yy];
	else if (x == xx)
		ans -= 1ll * (n - sz[last]) * sz[yy];
	else
		ans -= 1ll * sz[xx] * (n - sz[last]);
	cout << ans << endl;
	return 0;
}
