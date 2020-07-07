/*
 * TOUR.cpp
 *
 *  Created on: Sep 19, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int n;
vector<vector<int>> adj;
int vis[1001], indx[1001], low[1001], idx;
int comp[1001], compSZ[1001], deg[1001], compID;
stack<int> S;

void SCC(int nn) {
	vis[nn] = 1, S.push(nn), indx[nn] = low[nn] = idx++;
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
		compSZ[compID] = 0;
		int cur;
		do {
			cur = S.top();
			S.pop(), vis[cur] = 2;
			comp[cur] = compID;
			compSZ[compID]++;
		} while (cur != nn);
		compID++;
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		adj.assign(n + 1, vector<int>());
		memset(vis, 0, sizeof vis), idx = 0, compID = 0;
		memset(deg, 0, sizeof deg);
		for (int i = 1; i <= n; i++) {
			int m, x;
			scanf("%d", &m);
			while (m--) {
				scanf("%d", &x);
				adj[x].push_back(i);
			}
		}
		for (int i = 1; i <= n; i++)
			if (!vis[i])
				SCC(i);
		for (int i = 1; i <= n; i++)
			for (int j = 0; j < (int) adj[i].size(); j++)
				if (comp[i] != comp[adj[i][j]])
					deg[comp[adj[i][j]]]++;
		int ans = 0, cnt = 0;
		for (int i = 0; i < compID; i++)
			if (!deg[i])
				ans += compSZ[i], cnt++;
		printf("%d\n", cnt > 1 ? 0 : ans);
	}
	return 0;
}
