/*
 * 455C. Civilization.cpp
 *
 *  Created on: Mar 1, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 3e5 + 5;

int n, m, q, root[MAXN], rnk[MAXN], diam[MAXN], vis[MAXN], id;
vector<int> adj[MAXN];

void init() {
	for (int i = 1; i <= n; i++)
		root[i] = i, rnk[i] = 1;
}

int find(int x) {
	return root[x] == x ? x : root[x] = find(root[x]);
}

void merge(int a, int b) {
	int ra = find(a), rb = find(b);
	if (rnk[ra] < rnk[rb])
		root[ra] = root[rb];
	else
		root[rb] = root[ra];
	if (rnk[ra] == rnk[rb])
		rnk[ra]++;
}

pair<int, int> dfs(int x) {
	vis[x] = id;
	pair<int, int> ret { -1, x };
	for (auto to : adj[x]) {
		if (vis[to] == id)
			continue;
		ret = max(ret, dfs(to));
	}
	ret.first++;
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	scanf("%d%d%d", &n, &m, &q);
	init();
	while (m--) {
		int a, b;
		scanf("%d%d", &a, &b);
		adj[a].push_back(b), adj[b].push_back(a);
		merge(a, b);
	}
	for (int i = 1; i <= n; i++)
		if (!vis[i]) {
			id++;
			int x = dfs(i).second;
			id++;
			diam[find(i)] = dfs(x).first;
		}
	while (q--) {
		int t, x;
		scanf("%d%d", &t, &x);
		if (t == 1) {
			printf("%d\n", diam[find(x)]);
		} else {
			int y;
			scanf("%d", &y);
			int rx = find(x), ry = find(y);
			if (rx == ry)
				continue;
			int dx = (diam[rx] + 1) / 2, dy = (diam[ry] + 1) / 2;
			merge(rx, ry);
			diam[find(rx)] = max(max(diam[rx], diam[ry]), dx + dy + 1);
		}
	}
	return 0;
}
