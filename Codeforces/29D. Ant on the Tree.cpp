/*
 * 29D. Ant on the Tree.cpp
 *
 *  Created on: Oct 14, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 305;
const int MAXE = 2 * MAXN;
const int LOG = 9;

int n, leaves;
int head[MAXN], nxt[MAXE], to[MAXE], last;
int par[LOG][MAXN], vis[MAXN][MAXN], dep[MAXN];
vector<int> ans;

void addEdge(int f, int t) {
	to[last] = t;
	nxt[last] = head[f];
	head[f] = last++;
}

void DFS(int idx, int p, int d) {
	par[0][idx] = p, dep[idx] = d;
	for (int i = 1; i < LOG; i++)
		par[i][idx] = par[i - 1][par[i - 1][idx]];
	int ch = 0;
	for (int i = head[idx]; ~i; i = nxt[i])
		if (to[i] != p)
			ch++, DFS(to[i], idx, d + 1);
	leaves += ch == 0;
}

int lca(int u, int v) {
	if (dep[u] < dep[v])
		swap(u, v);
	for (int i = LOG - 1; ~i; i--)
		if (dep[par[i][u]] >= dep[v])
			u = par[i][u];
	if (u == v)
		return u;
	for (int i = LOG - 1; ~i; i--)
		if (par[i][u] != par[i][v])
			u = par[i][u], v = par[i][v];
	return par[0][u];
}

vector<int> getPath(int u, int v) {
	bool rev = 0;
	if (dep[u] > dep[v])
		rev = 1, swap(u, v);
	vector<int> ret;
	while (v != u) {
		ret.push_back(v);
		v = par[0][v];
	}
	ret.push_back(v);
	if (!rev)
		reverse(ret.begin(), ret.end());
	return ret;
}

void solve(int u, int v) {
	vector<int> temp = getPath(u, v);
	for (int i = 1; i < (int) temp.size(); i++) {
		vis[u][temp[i]]++, vis[temp[i]][u]++;
		if (vis[u][temp[i]] > 2) {
			printf("-1\n");
			exit(0);
		}
		ans.push_back(temp[i]);
		u = temp[i];
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	memset(head, -1, sizeof head);
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		addEdge(u, v), addEdge(v, u);
	}
	DFS(1, 0, 1);
	ans.push_back(1);
	int cur = 1, x;
	while (leaves--) {
		scanf("%d", &x);
		int l = lca(x, cur);
		solve(cur, l);
		solve(l, x);
		cur = x;
	}
	solve(cur, 1);
	for (int i = 0; i < (int) ans.size(); i++) {
		if (i)
			printf(" ");
		printf("%d", ans[i]);
	}
	printf("\n");
	return 0;
}
