/*
 * BOTTOM.cpp
 *
 *  Created on: Sep 19, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int n;
vector<vector<int>> adj;
int vis[5001], indx[5001], low[5001], idx;
int comp[5001], deg[5001], compID;
stack<int> S;

void SCC(int nn) {
	S.push(nn), vis[nn] = 1, indx[nn] = low[nn] = idx++;
	for (int i = 0; i < (int) adj[nn].size(); i++) {
		int to = adj[nn][i];
		if (!vis[to]) {
			SCC(to);
			low[nn] = min(low[nn], low[to]);
		} else if (vis[to] == 1) {
			low[nn] = min(low[nn], indx[to]);
		}
	}
	if (indx[nn] == low[nn]) {
		int cur;
		do {
			cur = S.top();
			S.pop(), vis[cur] = 2;
			comp[cur] = compID;
		} while (cur != nn);
		compID++;
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	while (scanf("%d", &n), n) {
		adj.assign(n + 1, vector<int>());
		memset(vis, 0, sizeof vis), idx = 0, compID = 0;
		memset(deg, 0, sizeof deg);
		int m;
		scanf("%d", &m);
		while (m--) {
			int u, v;
			scanf("%d%d", &u, &v);
			adj[u].push_back(v);
		}
		for (int i = 1; i <= n; i++)
			if (!vis[i])
				SCC(i);
		for (int nn = 1; nn <= n; nn++)
			for (int i = 0; i < (int) adj[nn].size(); i++)
				if (comp[nn] != comp[adj[nn][i]])
					deg[comp[nn]]++;
		vector<int> ans;
		for (int i = 1; i <= n; i++)
			if (!deg[comp[i]])
				ans.push_back(i);
		sort(ans.begin(), ans.end());
		for (int i = 0; i < (int) ans.size(); i++) {
			if (i)
				printf(" ");
			printf("%d", ans[i]);
		}
		printf("\n");
	}
	return 0;
}
