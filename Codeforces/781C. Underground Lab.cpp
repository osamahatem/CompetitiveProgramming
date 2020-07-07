/*
 * 781C. Underground Lab.cpp
 *
 *  Created on: Mar 8, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 2e5 + 5;

int n, m, k;
vector<int> adj[MAXN], path;
bool vis[MAXN];

void dfs(int idx) {
	vis[idx] = 1;
	path.push_back(idx);
	for (int i = 0; i < (int) adj[idx].size(); i++)
		if (!vis[adj[idx][i]]) {
			dfs(adj[idx][i]);
			path.push_back(idx);
		}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	scanf("%d%d%d", &n, &m, &k);
	while (m--) {
		int a, b;
		scanf("%d%d", &a, &b);
		adj[a].push_back(b), adj[b].push_back(a);
	}
	dfs(1);
	int lim = (n + n + k - 1) / k;
	for (int i = 0; i < k; i++) {
		vector<int> out;
		while (path.size() && (int) out.size() < lim) {
			out.push_back(path.back());
			path.pop_back();
		}
		if (out.empty())
			out.push_back(1);
		printf("%d", out.size());
		for (int j = 0; j < (int) out.size(); j++)
			printf(" %d", out[j]);
		printf("\n");
	}
	return 0;
}
