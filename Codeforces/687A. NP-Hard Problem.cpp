/*
 * 687A. NP-Hard Problem.cpp
 *
 *  Created on: Jun 29, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;

int side[MAXN];
vector<int> adj[MAXN], ans[2];

bool solve(int n, int s) {
	if (side[n])
		return side[n] == s;
	side[n] = s;
	ans[s - 1].push_back(n);
	for (int i = 0; i < (int) adj[n].size(); i++)
		if (!solve(adj[n][i], 3 - s))
			return false;
	return true;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, m;
	scanf("%d%d", &n, &m);
	while (m--) {
		int u, v;
		scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i = 1; i <= n; i++)
		if (!side[i] && !solve(i, 1)) {
			printf("-1\n");
			return 0;
		}
	printf("%d\n", ans[0].size());
	for (int i = 0; i < (int) ans[0].size(); i++) {
		if (i)
			printf(" ");
		printf("%d", ans[0][i]);
	}
	printf("\n%d\n", ans[1].size());
	for (int i = 0; i < (int) ans[1].size(); i++) {
		if (i)
			printf(" ");
		printf("%d", ans[1][i]);
	}
	printf("\n");
	return 0;
}
