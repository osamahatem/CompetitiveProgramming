/*
 * 980E. The Number Games.cpp
 *
 *  Created on: May 9, 2018
 *      Author: Osama Hatem
 */

/*
 * http://codeforces.com/blog/entry/59350
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e6 + 5;
const int LOGN = 20;

int n, k, par[LOGN][MAXN];
vector<int> adj[MAXN];
bool vis[MAXN];

void dfs(int idx, int p) {
	par[0][idx] = p;
	for (int i = 1; i < LOGN; i++)
		par[i][idx] = par[i - 1][par[i - 1][idx]];

	for (auto ch : adj[idx])
		if (ch != p)
			dfs(ch, idx);
}

int add(int idx, int rem) {
	int dist = 0, temp = idx;
	for (int i = LOGN - 1; ~i; i--)
		if (!vis[par[i][temp]])
			temp = par[i][temp], dist |= 1 << i;
	temp = par[0][temp], dist++;
	if (dist > rem)
		return 0;

	while (idx != temp) {
		vis[idx] = 1;
		idx = par[0][idx];
	}
	return dist;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> k;
	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b), adj[b].push_back(a);
	}

	dfs(n, 0);

	k = n - k - 1;
	vis[n] = vis[0] = 1;
	vector<int> ans;
	for (int i = n - 1; i; i--) {
		if (vis[i])
			continue;

		int temp = add(i, k);
		if (!temp)
			ans.push_back(i);
		k -= temp;
	}

	reverse(ans.begin(), ans.end());
	for (int i = 0; i < (int) ans.size(); i++)
		cout << ans[i] << " \n"[i + 1 == (int) ans.size()];
	return 0;
}
