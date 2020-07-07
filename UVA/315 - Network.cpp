/*
 * 315 - Network.cpp
 *
 *  Created on: Sep 27, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const char NL = 10;

int n;
vector<vector<int>> adj;
int idx[100], low[100], id;
bool vis[100];

int DFS(int cur, int p) {
	idx[cur] = low[cur] = ++id;
	vis[cur] = 1;
	int ret = 0, ch = 0;
	bool art = false;
	for (int i = 0; i < (int) adj[cur].size(); i++) {
		int to = adj[cur][i];
		if (!vis[to]) {
			ret += DFS(to, cur), ch++;
			low[cur] = min(low[cur], low[to]);
			if ((p != -1 && low[to] >= idx[cur]) || (p == -1 && ch > 1))
				art = true;
		} else if (to != p) {
			low[cur] = min(low[cur], idx[to]);
		}
	}
	ret += art;
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	while (scanf("%d", &n), n) {
		adj.assign(n, vector<int>());
		int u;
		while (scanf("%d", &u), u) {
			u--;
			int v;
			char c;
			do {
				scanf("%d%c", &v, &c);
				v--;
				adj[v].push_back(u), adj[u].push_back(v);
			} while (c != NL);
		}
		memset(vis, 0, sizeof vis), id = 0;
		printf("%d\n", DFS(0, -1));
	}
	return 0;
}
