/*
 * 276E. Little Girl and Problem on Trees.cpp
 *
 *  Created on: Jun 20, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;

int n, q, pos[MAXN], chainID[MAXN], depth[MAXN], curPos = 1;
int tree1[MAXN], tree2[MAXN];
vector<int> adj[MAXN];
vector<vector<int>> chain;

void _update(int tree[], int idx, int val) {
	while (idx < MAXN) {
		tree[idx] += val;
		idx += idx & -idx;
	}
}

void update(int tree[], int l, int r, int val) {
	_update(tree, l, val);
	_update(tree, r + 1, -val);
}

int query(int tree[], int idx) {
	int ret = 0;
	while (idx > 0) {
		ret += tree[idx];
		idx -= idx & -idx;
	}
	return ret;
}

void DFS(int idx, int _chainID, int _depth, int par) {
	chain[_chainID].push_back(idx);
	chainID[idx] = _chainID;
	depth[idx] = _depth;
	pos[idx] = ++curPos;
	for (int i = 0; i < (int) adj[idx].size(); i++)
		if (adj[idx][i] != par)
			DFS(adj[idx][i], _chainID, _depth + 1, idx);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	scanf("%d%d", &n, &q);
	for (int i = 1; i < n; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	pos[1] = 1, depth[1] = 1;
	chain.resize(adj[1].size());
	for (int i = 0; i < (int) adj[1].size(); i++)
		DFS(adj[1][i], i, 2, 1);
	while (q--) {
		int t, v;
		scanf("%d%d", &t, &v);
		if (t)
			printf("%d\n", query(tree1, depth[v]) + query(tree2, pos[v]));
		else {
			int x, d;
			scanf("%d%d", &x, &d);
			int dd = d - depth[v] + 2;
			if (dd > 0)
				update(tree1, 1, dd, x);
			if (v != 1) {
				int _chainID = chainID[v];
				int l = max(dd + 1, depth[v] - d), r = depth[v] + d;
				l -= 2, r -= 2;
				if (l >= (int) chain[_chainID].size())
					continue;
				r = min(r, (int) chain[_chainID].size() - 1);
				l = pos[chain[_chainID][l]], r = pos[chain[_chainID][r]];
				update(tree2, l, r, x);
			}
		}
	}
	return 0;
}
