/*
 * 588E. Duff in the Army.cpp
 *
 *  Created on: Oct 15, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;
const int MAXE = 2 * MAXN;
const int LOGN = 17;

int head[MAXN], nxt[MAXE], to[MAXE], last;
int par[LOGN][MAXN];
int treeSize[MAXN], depth[MAXN];
vector<int> segTree[4 * MAXN], segArr[MAXN];
int posInSeg[MAXN], ptr;
int chainHead[MAXN], chainID[MAXN], curChain;
vector<int> id[MAXN];
set<int> ans;

void init() {
	memset(head, -1, sizeof head);
	memset(par, -1, sizeof par);
	memset(chainHead, -1, sizeof chainHead);
}

void addEdge(int f, int t) {
	to[last] = t;
	nxt[last] = head[f];
	head[f] = last++;
}

void addBiEdge(int f, int t) {
	addEdge(f, t);
	addEdge(t, f);
}

void DFS(int cur, int _depth = 0) {
	for (int i = head[cur]; i != -1; i = nxt[i]) {
		if (to[i] == par[0][cur])
			continue;
		par[0][to[i]] = cur;
		DFS(to[i], _depth + 1);
		treeSize[cur] += treeSize[to[i]];
	}
	treeSize[cur]++;
	depth[cur] = _depth;
}

void build_par() {
	for (int j = 1; j < LOGN; j++)
		for (int i = 0; i < MAXN; i++)
			if (par[j - 1][i] != -1)
				par[j][i] = par[j - 1][par[j - 1][i]];
}

void HLD(int curNode) {
	if (chainHead[curChain] == -1)
		chainHead[curChain] = curNode;
	chainID[curNode] = curChain;
	posInSeg[curNode] = ptr;
	vector<int> temp = id[curNode];
	while (temp.size() > 10)
		temp.pop_back();
	segArr[ptr++] = temp;

	int sc = -1;
	for (int i = head[curNode]; i != -1; i = nxt[i])
		if (par[0][curNode] != to[i]
				&& (sc == -1 || treeSize[to[i]] > treeSize[sc]))
			sc = to[i];
	if (sc != -1)
		HLD(sc);

	for (int i = head[curNode]; i != -1; i = nxt[i])
		if (par[0][curNode] != to[i] && to[i] != sc) {
			curChain++;
			HLD(to[i]);
		}
}

int ancestor(int u, int _depth) {
	int diff = depth[u] - _depth;
	for (int i = 0; i < LOGN; i++)
		if ((diff >> i) & 1)
			u = par[i][u];
	return u;
}

int LCA(int u, int v) {
	if (depth[u] < depth[v])
		swap(u, v);
	u = ancestor(u, depth[v]);
	if (u == v)
		return u;
	for (int i = LOGN - 1; i >= 0; i--)
		if (par[i][u] != par[i][v])
			u = par[i][u], v = par[i][v];
	return par[0][u];
}

void build_tree(int n = 1, int s = 0, int e = MAXN - 1) {
	if (s == e) {
		segTree[n] = segArr[s];
		return;
	}
	int mid = (s + e) / 2;
	build_tree(n * 2, s, mid);
	build_tree(n * 2 + 1, mid + 1, e);
	for (int i = 0; i < (int) segTree[n * 2].size(); i++)
		segTree[n].push_back(segTree[n * 2][i]);
	for (int i = 0; i < (int) segTree[n * 2 + 1].size(); i++)
		segTree[n].push_back(segTree[n * 2 + 1][i]);
	sort(segTree[n].begin(), segTree[n].end());
	while (segTree[n].size() > 10)
		segTree[n].pop_back();
}

void query_tree(int qs, int qe, int n = 1, int s = 0, int e = MAXN - 1) {
	if (qs > e || qe < s || qs > qe)
		return;
	if (s >= qs && e <= qe) {
		ans.insert(segTree[n].begin(), segTree[n].end());
		while (ans.size() > 10)
			ans.erase(--(ans.end()));
		return;
	}
	int mid = (s + e) / 2;
	query_tree(qs, qe, n * 2, s, mid);
	query_tree(qs, qe, n * 2 + 1, mid + 1, e);
}

void query_up(int u, int v) {
	int uc = chainID[u], vc = chainID[v];
	vector<int> ret, temp;
	while (uc != vc) {
		query_tree(posInSeg[chainHead[uc]], posInSeg[u]);
		u = chainHead[uc];
		u = par[0][u];
		uc = chainID[u];
	}
	query_tree(posInSeg[v], posInSeg[u]);
}

void query(int u, int v) {
	int lca = LCA(u, v);
	ans.clear();
	query_up(u, lca);
	query_up(v, lca);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	init();
	int n, m, q, u, v, a;
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 1; i < n; i++) {
		scanf("%d%d", &u, &v);
		addBiEdge(u, v);
	}
	for (int i = 1; i <= m; i++) {
		scanf("%d", &u);
		id[u].push_back(i);
	}
	DFS(1);
	build_par();
	HLD(1);
	build_tree();
	while (q--) {
		scanf("%d%d%d", &u, &v, &a);
		query(u, v);
		while ((int) ans.size() > a)
			ans.erase(--(ans.end()));
		printf("%d", ans.size());
		for (auto it = ans.begin(); it != ans.end(); it++)
			printf(" %d", *it);
		printf("\n");
	}
	return 0;
}
