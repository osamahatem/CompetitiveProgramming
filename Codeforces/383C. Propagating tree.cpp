/*
 * 383C. Propagating tree.cpp
 *
 *  Created on: Mar 12, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 2e5 + 5;

int N, Q, init[MAXN];
int tree[MAXN];
int depth[MAXN], order[MAXN], subtree[MAXN], id;
vector<int> adj[MAXN];

void update(int idx, int val) {
	for (; idx && idx <= N; idx += idx & -idx)
		tree[idx] += val;
}

int query(int idx) {
	int ret = 0;
	for (; idx; idx -= idx & -idx)
		ret += tree[idx];
	return ret;
}

int dfs(int idx, int dep, int par) {
	depth[idx] = dep, order[idx] = ++id, subtree[idx] = id;
	for (auto x : adj[idx])
		if (x != par)
			subtree[idx] = dfs(x, dep + 1, idx);
	return subtree[idx];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	scanf("%d%d", &N, &Q);
	for (int i = 1; i <= N; i++)
		scanf("%d", &init[i]);
	for (int i = 1; i < N; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		adj[a].push_back(b), adj[b].push_back(a);
	}
	dfs(1, 0, -1);
	while (Q--) {
		int t, x, val;
		scanf("%d%d", &t, &x);
		if (t == 1) {
			scanf("%d", &val);
			if (depth[x] & 1)
				val = -val;
			update(order[x], val), update(subtree[x] + 1, -val);
		} else {
			printf("%d\n", query(order[x]) * (depth[x] & 1 ? -1 : 1) + init[x]);
		}
	}
	return 0;
}
