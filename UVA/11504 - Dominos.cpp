/*
 * 11504 - Dominos.cpp
 *
 *  Created on: Sep 17, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;

int n, m;
int head[MAXN], nxt[MAXN], to[MAXN], last;
int vis[MAXN], indx[MAXN], low[MAXN], idx;
int comp[MAXN], deg[MAXN], compID;
stack<int> S;

void addEdge(int f, int t) {
	to[last] = t;
	nxt[last] = head[f];
	head[f] = last++;
}

void SCC(int nn) {
	vis[nn] = 1, S.push(nn), indx[nn] = low[nn] = idx++;
	for (int i = head[nn]; i != -1; i = nxt[i]) {
		if (!vis[to[i]]) {
			SCC(to[i]);
			low[nn] = min(low[nn], low[to[i]]);
		} else if (vis[to[i]] == 1) {
			low[nn] = min(low[nn], indx[to[i]]);
		}
	}
	if (low[nn] == indx[nn]) {
		int cur;
		do {
			cur = S.top();
			S.pop();
			vis[cur] = 2, comp[cur] = compID;
		} while (cur != nn);
		compID++;
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int T;
	scanf("%d", &T);
	while (T--) {
		memset(head, -1, sizeof head), last = 0;
		memset(vis, 0, sizeof vis), idx = 0;
		memset(deg, 0, sizeof deg), compID = 0;
		scanf("%d%d", &n, &m);
		while (m--) {
			int u, v;
			scanf("%d%d", &u, &v);
			addEdge(u, v);
		}
		for (int i = 1; i <= n; i++)
			if (!vis[i])
				SCC(i);
		for (int nn = 1; nn <= n; nn++) {
			for (int i = head[nn]; i != -1; i = nxt[i]) {
				if (comp[nn] != comp[to[i]])
					deg[comp[to[i]]]++;
			}
		}
		int ans = 0;
		for (int i = 0; i < compID; i++)
			ans += deg[i] == 0;
		printf("%d\n", ans);
	}
	return 0;
}
