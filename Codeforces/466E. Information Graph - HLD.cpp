/*
 * 466E. Information Graph - HLD.cpp
 *
 *  Created on: Jun 22, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;
const int LOGN = 17;

int head[MAXN], nxt[MAXN], to[MAXN], cost[MAXN], last;
int docEmployee[MAXN], docTime[MAXN], docs;
int par[LOGN][MAXN];
int treeSize[MAXN], depth[MAXN];
int segTree[4 * MAXN], segArr[MAXN], posInSeg[MAXN], ptr;
int chainHead[MAXN], chainID[MAXN], curChain;

void init() {
	memset(head, -1, sizeof head);
	memset(par, -1, sizeof par);
	memset(chainHead, -1, sizeof chainHead);
}

void addEdge(int f, int t, int c) {
	to[last] = t;
	cost[last] = c;
	nxt[last] = head[f];
	head[f] = last++;
}

void DFS(int cur, int _depth = 0) {
	for (int i = head[cur]; i != -1; i = nxt[i]) {
		DFS(to[i], _depth + 1);
		treeSize[cur] += treeSize[to[i]];
	}
	treeSize[cur]++;
	depth[cur] = _depth;
}

void HLD(int curNode, int _cost = 0) {
	if (chainHead[curChain] == -1)
		chainHead[curChain] = curNode;
	chainID[curNode] = curChain;
	posInSeg[curNode] = ptr;
	segArr[ptr++] = _cost;

	int sc = -1, ncost;
	for (int i = head[curNode]; i != -1; i = nxt[i])
		if (sc == -1 || treeSize[to[i]] > treeSize[sc])
			sc = to[i], ncost = cost[i];
	if (sc != -1)
		HLD(sc, ncost);

	for (int i = head[curNode]; i != -1; i = nxt[i])
		if (to[i] != sc) {
			curChain++;
			HLD(to[i], cost[i]);
		}
}

void build_par() {
	for (int j = 1; j < LOGN; j++)
		for (int i = 0; i < MAXN; i++)
			if (par[j - 1][i] != -1)
				par[j][i] = par[j - 1][par[j - 1][i]];
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
	segTree[n] = max(segTree[n * 2], segTree[n * 2 + 1]);
}

int query_tree(int qs, int qe, int n = 1, int s = 0, int e = MAXN - 1) {
	if (qs > e || qe < s || qs > qe)
		return 0;
	if (s >= qs && e <= qe)
		return segTree[n];
	int mid = (s + e) / 2;
	int ret = query_tree(qs, qe, n * 2, s, mid);
	ret = max(ret, query_tree(qs, qe, n * 2 + 1, mid + 1, e));
	return ret;
}

int query_up(int u, int v) {
	int uc = chainID[u], vc = chainID[v], ans = 0;
	while (uc != vc) {
		ans = max(ans, query_tree(posInSeg[chainHead[uc]], posInSeg[u]));
		u = chainHead[uc];
		u = par[0][u];
		uc = chainID[u];
	}
	ans = max(ans, query_tree(posInSeg[v] + 1, posInSeg[u]));
	return ans;
}

bool query(int t_emp, int _doc) {
	int s_emp = docEmployee[_doc];
	int lca = LCA(s_emp, t_emp);
	if (lca == -1 || lca != t_emp)
		return false;
	return (query_up(s_emp, t_emp) > docTime[_doc] ? false : true);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	init();
	int n, m, t, x, y;
	vector<pair<int, int>> queries;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &t, &x);
		if (t == 1) {
			scanf("%d", &y);
			addEdge(y, x, i);
			par[0][x] = y;
		} else if (t == 2) {
			docEmployee[++docs] = x;
			docTime[docs] = i;
		} else {
			scanf("%d", &y);
			queries.push_back(make_pair(x, y));
		}
	}
	for (int i = 1; i <= n; i++)
		if (par[0][i] == -1)
			DFS(i), HLD(i);
	build_par(), build_tree();
	for (int i = 0; i < (int) queries.size(); i++)
		if (query(queries[i].first, queries[i].second))
			printf("YES\n");
		else
			printf("NO\n");
	return 0;
}
