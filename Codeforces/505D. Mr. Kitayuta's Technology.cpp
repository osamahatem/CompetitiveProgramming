/*
 * 505D. Mr. Kitayuta's Technology.cpp
 *
 *  Created on: Feb 7, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;

vector<int> dir[MAXN], undir[MAXN];
int vis[MAXN], vid[MAXN], id = 0;
bool cycle[MAXN];

int dfs(int n, vector<int> adj[]) {
	if (vis[n] == 1)
		vis[n] = 2;
	if (vis[n] == 0)
		vis[n] = 1, vid[n] = id;
	int ret = 1;
	for (int i = 0; i < (int) adj[n].size(); i++) {
		int t = adj[n][i];
		if (vis[n] == 2 && vis[t] == 2)
			cycle[vid[n]] = true;
		if (vis[n] <= vis[t])
			continue;
		ret += dfs(t, adj);
	}
	if (vis[n] == 2)
		vis[n] = 3;
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, m, a, b, ans = 0;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		dir[a].push_back(b);
		undir[a].push_back(b);
		undir[b].push_back(a);
	}
	for (int i = 1; i <= n; i++)
		if (vis[i] == 0)
			id++, ans += dfs(i, undir) - 1;
	for (int i = 1; i <= n; i++)
		if (vis[i] == 1)
			dfs(i, dir);
	for (int i = 1; i <= n; i++)
		ans += cycle[i];
	cout << ans << endl;
	return 0;
}
