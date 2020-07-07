/*
 * 1108 - Mining Your Own Business.cpp
 *
 *  Created on: Oct 2, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 5e4 + 5;
const int MAXE = 2 * MAXN;

int n, m, T;
int head[MAXN], nxt[MAXE], to[MAXE], last;
int indx[MAXN], low[MAXN], id;
bool vis[MAXN], art[MAXN];
set<int> adjArt;

void init() {
	memset(head, -1, sizeof head), last = 0;
	memset(vis, 0, sizeof vis), id = 0;
	n = 1;
}

void addEdge(int f, int t) {
	to[last] = t;
	nxt[last] = head[f];
	head[f] = last++;
}

void tarjan(int idx, int p) {
	indx[idx] = low[idx] = ++id;
	art[idx] = false, vis[idx] = 1;
	int ch = 0;
	for (int i = head[idx]; i != -1; i = nxt[i]) {
		if (!vis[to[i]]) {
			ch++;
			tarjan(to[i], idx);
			low[idx] = min(low[idx], low[to[i]]);
			if ((p == -1 && ch > 1) || (p != -1 && low[to[i]] >= indx[idx]))
				art[idx] = true;
		} else if (to[i] != p) {
			low[idx] = min(low[idx], indx[to[i]]);
		}
	}
}

int DFS(int idx) {
	vis[idx] = 1;
	int ret = 1;
	for (int i = head[idx]; i != -1; i = nxt[i]) {
		if (art[to[i]])
			adjArt.insert(to[i]);
		if (!art[to[i]] && !vis[to[i]])
			ret += DFS(to[i]);
	}
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	while (scanf("%d", &m), m) {
		init();
		while (m--) {
			int u, v;
			scanf("%d%d", &u, &v);
			addEdge(u, v), addEdge(v, u);
			n = max(n, max(u, v));
		}
		tarjan(1, -1);
		memset(vis, 0, sizeof vis);
		int ans = 0;
		long long cnt = 1;
		for (int i = 1; i <= n; i++) {
			if (!vis[i] && !art[i]) {
				adjArt.clear();
				int x = DFS(i);
				if (adjArt.size() < 2) {
					ans++;
					cnt *= x;
				}
			}
		}
		if (ans == 1 && cnt == n)
			ans = 2, cnt = 1ll * n * (n - 1) / 2;
		printf("Case %d: %d %lld\n", ++T, ans, cnt);
	}
	return 0;
}
