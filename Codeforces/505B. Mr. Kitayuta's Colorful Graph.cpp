/*
 * 505B. Mr. Kitayuta's Colorful Graph.cpp
 *
 *  Created on: Jan 18, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

vector<int> adj[105][105];
vector<set<int> > ans[105];
bool vis[105];

void DFS(int n, int c) {
	vis[n] = 1;
	int sz = (int) ans[c].size();
	ans[c][sz - 1].insert(n);
	for (int i = 0; i < (int) adj[n][c].size(); i++) {
		int t = adj[n][c][i];
		if (!vis[t])
			DFS(t, c);
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	memset(adj, -1, sizeof adj);
	int q, n, m, a, b, c;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		adj[a][c].push_back(b);
		adj[b][c].push_back(a);
	}
	for (int i = 1; i <= m; i++) {
		memset(vis, 0, sizeof vis);
		for (int j = 1; j <= n; j++) {
			if (!vis[j])
				ans[i].push_back(set<int>()), DFS(j, i);
			vis[j] = 1;
		}
	}
	cin >> q;
	while (q--) {
		int out = 0;
		cin >> a >> b;
		for (int i = 1; i <= m; i++)
			for (int j = 0; j < (int) ans[i].size(); j++)
				if (ans[i][j].count(a) && ans[i][j].count(b))
					out++;
		cout << out << endl;
	}
	return 0;
}
