/*
 * 11838 - Come and Go.cpp
 *
 *  Created on: Sep 17, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 2001;
const int MAXE = 2 * MAXN * MAXN;

int n, m;
int head[MAXN], nxt[MAXE], to[MAXE], last;
int vis[MAXN], indx[MAXN], low[MAXN], idx;
stack<int> S;

void addEdge(int f, int t) {
	to[last] = t;
	nxt[last] = head[f];
	head[f] = last++;
}

int SCC(int nn) {
	vis[nn] = 1, S.push(nn), indx[nn] = low[nn] = idx++;
	int ret = 0;
	for (int i = head[nn]; i != -1; i = nxt[i]) {
		if (!vis[to[i]]) {
			ret += SCC(to[i]);
			low[nn] = min(low[nn], low[to[i]]);
		} else if (vis[to[i]] == 1) {
			low[nn] = min(low[nn], indx[to[i]]);
		}
	}
	if (low[nn] == indx[nn]) {
		ret++;
		int cur;
		do {
			cur = S.top();
			S.pop(), vis[cur] = 2;
		} while (cur != nn);
	}
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	while (scanf("%d%d", &n, &m), n || m) {
		memset(head, -1, sizeof head), last = 0;
		memset(vis, 0, sizeof vis), idx = 0;
		while (m--) {
			int u, v, p;
			scanf("%d%d%d", &u, &v, &p);
			addEdge(u, v);
			if (p == 2)
				addEdge(v, u);
		}
		int ans = 0;
		for (int i = 1; i <= n; i++)
			if (!vis[i])
				ans += SCC(i);
		printf("%d\n", ans == 1);
	}
	return 0;
}
