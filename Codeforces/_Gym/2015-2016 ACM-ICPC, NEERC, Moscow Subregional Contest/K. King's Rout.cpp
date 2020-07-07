/*
 * K. King's Rout.cpp
 *
 *  Created on: Sep 27, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

vector<vector<int>> adj;
int deg[200000];
vector<int> ans;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, m;
	scanf("%d%d", &n, &m);
	adj.assign(n, vector<int>());
	while (m--) {
		int u, v;
		scanf("%d%d", &u, &v);
		u--, v--;
		adj[v].push_back(u);
		deg[u]++;
	}
	set<int> S;
	for (int i = 0; i < n; i++)
		if (!deg[i])
			S.insert(-i);
	while (S.size()) {
		int x = -(*S.begin());
		S.erase(S.begin());
		ans.push_back(x + 1);
		for (int i = 0; i < (int) adj[x].size(); i++) {
			int to = adj[x][i];
			deg[to]--;
			if (!deg[to])
				S.insert(-to);
		}
	}
	reverse(ans.begin(), ans.end());
	for (int i = 0; i < n; i++) {
		if (i)
			printf(" ");
		printf("%d", ans[i]);
	}
	printf("\n");
	return 0;
}
