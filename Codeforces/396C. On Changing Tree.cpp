/*
 * 396C. On Changing Tree.cpp
 *
 *  Created on: Sep 14, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 3e5 + 5;
const int MOD = 1000000007;

struct node {
	int staticSum, variableSum;
};

int head[MAXN], to[MAXN], nxt[MAXN], last;
int N, Q, dep[MAXN], order[MAXN], id[MAXN], subSZ[MAXN], timer;
node tree[4 * MAXN], lazy[4 * MAXN];

void addEdge(int f, int t) {
	to[last] = t;
	nxt[last] = head[f];
	head[f] = last++;
}

void dfs(int n) {
	order[n] = timer, id[timer] = n;
	timer++;
	for (int i = head[n]; i != -1; i = nxt[i]) {
		dep[to[i]] = dep[n] + 1;
		dfs(to[i]);
		subSZ[n] += subSZ[to[i]];
	}
	subSZ[n]++;
}

void relax(int n, int s, int e) {
	tree[n].staticSum = (tree[n].staticSum + lazy[n].staticSum) % MOD;
	tree[n].variableSum = (tree[n].variableSum + lazy[n].variableSum) % MOD;
	if (s != e) {
		lazy[n * 2].staticSum = (lazy[n * 2].staticSum + lazy[n].staticSum)
				% MOD;
		lazy[n * 2].variableSum =
				(lazy[n * 2].variableSum + lazy[n].variableSum) % MOD;
		lazy[n * 2 + 1].staticSum = (lazy[n * 2 + 1].staticSum
				+ lazy[n].staticSum) % MOD;
		lazy[n * 2 + 1].variableSum = (lazy[n * 2 + 1].variableSum
				+ lazy[n].variableSum) % MOD;
	}
	lazy[n].staticSum = lazy[n].variableSum = 0;
}

void update(int qs, int qe, int sSum, int vSum, int n = 1, int s = 0,
		int e = N - 1) {
	relax(n, s, e);
	if (qs > e || qe < s)
		return;
	if (s >= qs && e <= qe) {
		lazy[n].staticSum = (lazy[n].staticSum + sSum) % MOD;
		lazy[n].variableSum = (lazy[n].variableSum + vSum) % MOD;
		relax(n, s, e);
		return;
	}
	int mid = (s + e) / 2;
	update(qs, qe, sSum, vSum, n * 2, s, mid);
	update(qs, qe, sSum, vSum, n * 2 + 1, mid + 1, e);
}

int query(int q, int n = 1, int s = 0, int e = N - 1) {
	relax(n, s, e);
	if (q > e || q < s)
		return 0;
	if (s == e)
		return (tree[n].staticSum + 1ll * tree[n].variableSum * dep[id[s]])
				% MOD;
	int mid = (s + e) / 2;
	return (query(q, n * 2, s, mid) + query(q, n * 2 + 1, mid + 1, e)) % MOD;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	memset(head, -1, sizeof head);
	scanf("%d", &N);
	int t, v, x, k;
	for (int i = 2; i <= N; i++) {
		scanf("%d", &x);
		addEdge(x, i);
	}
	fill(tree, tree + 4 * MAXN, node { 0, 0 });
	fill(lazy, lazy + 4 * MAXN, node { 0, 0 });
	dfs(1);
	scanf("%d", &Q);
	while (Q--) {
		scanf("%d%d", &t, &v);
		if (t == 1) {
			scanf("%d%d", &x, &k);
			int sSum = ((1ll * k * dep[v] + x) % MOD + MOD) % MOD;
			int vSum = MOD - k;
			update(order[v], order[v] + subSZ[v] - 1, sSum, vSum);
		} else
			printf("%d\n", query(order[v]));
	}
	return 0;
}
