/*
 * COCONUTS.cpp
 *
 *  Created on: Oct 21, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 305;
const int MAXE = MAXN * MAXN * 2;
const int SRC = MAXN - 1;
const int SNK = MAXN - 2;

int head[MAXN], nxt[MAXE], to[MAXE], cap[MAXE], last;
int vis[MAXN], id;

void init() {
	memset(head, -1, sizeof head);
	last = 0;
}

void addEdge(int u, int v, int c) {
	to[last] = v;
	cap[last] = c;
	nxt[last] = head[u];
	head[u] = last++;
}

void addAugEdge(int u, int v, int c1, int c2 = 0) {
	addEdge(u, v, c1);
	addEdge(v, u, c2);
}

bool DFS(int n) {
	vis[n] = id;
	for (int i = head[n]; ~i; i = nxt[i]) {
		if (cap[i] && vis[to[i]] != id && (to[i] == SNK || DFS(to[i]))) {
			cap[i]--, cap[i ^ 1]++;
			return true;
		}
	}
	return false;
}

int maxFlow() {
	int ret = 0;
	while (id++, DFS(SRC))
		ret++;
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, m;
	while (scanf("%d%d", &n, &m), n || m) {
		init();
		for (int i = 1; i <= n; i++) {
			int t;
			scanf("%d", &t);
			if (t)
				addAugEdge(SRC, i, 1, 1);
			else
				addAugEdge(i, SNK, 1, 1);
		}
		while (m--) {
			int u, v;
			scanf("%d%d", &u, &v);
			addAugEdge(u, v, 1, 1);
		}
		printf("%d\n", maxFlow());
	}
	return 0;
}
