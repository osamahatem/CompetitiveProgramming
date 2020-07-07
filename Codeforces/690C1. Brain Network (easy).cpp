/*
 * 690C1. Brain Network (easy).cpp
 *
 *  Created on: Jul 10, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1005;

vector<int> adj[MAXN];
bool vis[MAXN];

int solve(int n) {
	vis[n] = 1;
	int ret = 1;
	for (int i = 0; i < (int) adj[n].size(); i++)
		if (!vis[adj[n][i]])
			ret += solve(adj[n][i]);
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, m, a, b;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	printf("%s\n", m + 1 == n && solve(1) == n ? "yes" : "no");
	return 0;
}
