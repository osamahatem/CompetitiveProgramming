/*
 * ANCESTOR.cpp
 *
 *  Created on: Jun 5, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 5e5 + 5;

int N;
vector<int> adj[MAXN];
int in[MAXN], out[MAXN], id;
int tree[MAXN];
int ans[MAXN];

void init() {
	for (int i = 1; i <= N; i++)
		ans[i] = 0, adj[i].clear();
	id = 0;
}

void DFS(int node, int par) {
	in[node] = ++id;
	for (auto x : adj[node])
		if (x != par)
			DFS(x, node);
	out[node] = id;
}

void update(int idx, int val) {
	for (; idx <= N; idx += idx & -idx)
		tree[idx] += val;
}

int query(int idx) {
	int ret = 0;
	for (; idx; idx -= idx & -idx)
		ret += tree[idx];
	return ret;
}

void solve(int node, int par) {
	ans[node] = query(in[node]);
	update(in[node], 1), update(out[node] + 1, -1);
	for (auto x : adj[node])
		if (x != par)
			solve(x, node);
	update(in[node], -1), update(out[node] + 1, 1);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		init();
		for (int i = 1; i < N; i++) {
			int u, v;
			scanf("%d%d", &u, &v);
			adj[u].push_back(v), adj[v].push_back(u);
		}
		DFS(1, 0);
		init();
		for (int i = 1; i < N; i++) {
			int u, v;
			scanf("%d%d", &u, &v);
			adj[u].push_back(v), adj[v].push_back(u);
		}
		solve(1, 0);
		for (int i = 1; i <= N; i++) {
			if (i > 1)
				printf(" ");
			printf("%d", ans[i]);
		}
		printf("\n");
	}
	return 0;
}
