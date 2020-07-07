/*
 * G. Gangsters in Central City.cpp
 *
 *  Created on: Nov 1, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;
const int LOG = 17;

int n, q, par[LOG][MAXN], depth[MAXN], indx[MAXN], idx;
int ancestor[MAXN], lastAns[MAXN], tree[MAXN];
vector<int> adj[MAXN];

struct cmp {
	const bool operator()(const int& a, const int& b) const {
		return indx[a] < indx[b];
	}
};

set<int, cmp> cur[MAXN];

int getKth(int x, int d) {
	for (int i = LOG - 1; ~i; i--)
		if (d >= (1 << i))
			x = par[i][x], d -= (1 << i);
	return x;
}

int LCA(int u, int v) {
	if (depth[u] > depth[v])
		swap(u, v);
	for (int i = LOG - 1; ~i; i--)
		if (depth[v] - (1 << i) >= depth[u])
			v = par[i][v];
	if (u == v)
		return u;
	for (int i = LOG - 1; ~i; i--)
		if (par[i][u] != par[i][v])
			u = par[i][u], v = par[i][v];
	return par[0][u];
}

void DFS(int x) {
	indx[x] = ++idx;
	if (adj[x].empty())
		tree[x]++;
	for (int i = 0; i < (int) adj[x].size(); i++) {
		DFS(adj[x][i]);
		tree[x] += tree[adj[x][i]];
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	freopen("gangsters.in", "r", stdin);
	freopen("gangsters.out", "w", stdout);
	scanf("%d%d", &n, &q);
	for (int i = 2; i <= n; i++) {
		scanf("%d", &par[0][i]);
		for (int j = 1; j < LOG; j++)
			par[j][i] = par[j - 1][par[j - 1][i]];
		adj[par[0][i]].push_back(i);
		depth[i] = depth[par[0][i]] + 1;
		ancestor[i] = getKth(i, depth[i] - 1);
	}
	DFS(1);
	int ans = 0, cnt = 0;
	while (q--) {
		char buff[3];
		int x;
		scanf("%s%d", buff, &x);
		int xx = ancestor[x];
		if (buff[0] == '+') {
			if (cur[xx].empty())
				ans++;
			cur[xx].insert(x);
			int u = *(cur[xx].begin()), v = *(--cur[xx].end());
			int lca = LCA(u, v);
			cnt -= lastAns[xx];
			lastAns[xx] = tree[lca] - cur[xx].size();
			cnt += lastAns[xx];
		} else {
			cur[xx].erase(x);
			cnt -= lastAns[xx];
			if (cur[xx].empty()) {
				ans--;
				lastAns[xx] = 0;
			} else {
				int u = *(cur[xx].begin()), v = *(--cur[xx].end());
				int lca = LCA(u, v);
				lastAns[xx] = tree[lca] - cur[xx].size();
				cnt += lastAns[xx];
			}
		}
		printf("%d %d\n", ans, cnt);
	}
	return 0;
}
