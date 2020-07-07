/*
 * 610 - Street Directions.cpp
 *
 *  Created on: Oct 2, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e3 + 5;
const int MAXE = MAXN * MAXN / 2;

int n, m, T;
int head[MAXN], nxt[MAXE], to[MAXE], last;
int indx[MAXN], low[MAXN], id;
bool vis[MAXN], visE[MAXE];

void init() {
	memset(head, -1, sizeof head), last = 0;
	memset(vis, 0, sizeof vis), id = 0;
	memset(visE, 0, sizeof visE);
}

void addEdge(int f, int t) {
	to[last] = t;
	nxt[last] = head[f];
	head[f] = last++;
}

void solve(int idx, int p) {
	vis[idx] = 1, indx[idx] = low[idx] = ++id;
	for (int i = head[idx]; i != -1; i = nxt[i]) {
		if (to[i] != p && !visE[i])
			printf("%d %d\n", idx, to[i]), visE[i] = visE[i ^ 1] = 1;
		if (!vis[to[i]]) {
			solve(to[i], idx);
			low[idx] = min(low[idx], low[to[i]]);
			if (low[to[i]] > indx[idx])
				printf("%d %d\n", to[i], idx);
		} else if (to[i] != p) {
			low[idx] = min(low[idx], indx[to[i]]);
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	while (scanf("%d%d", &n, &m), n) {
		printf("%d\n\n", ++T);
		init();
		while (m--) {
			int u, v;
			scanf("%d%d", &u, &v);
			addEdge(u, v), addEdge(v, u);
		}
		solve(1, -1);
		printf("#\n");
	}
	return 0;
}
