/*
 * 10608 - Friends.cpp
 *
 *  Created on: Mar 28, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 3e4 + 5;
const int MAXE = 5e5 + 5;

int head[MAXN], to[2 * MAXE], nxt[2 * MAXE], last;
bool vis[MAXN];

void addEdge(int f, int t) {
	nxt[last] = head[f];
	to[last] = t;
	head[f] = last++;
}

void addBiEdge(int f, int t) {
	addEdge(f, t);
	addEdge(t, f);
}

int solve(int idx) {
	vis[idx] = 1;
	int ret = 1;
	for (int e = head[idx]; e != -1; e = nxt[e])
		if (!vis[to[e]])
			ret += solve(to[e]);
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int T;
	scanf("%d", &T);
	while (T--) {
		memset(vis, 0, sizeof vis);
		memset(head, -1, sizeof head);
		last = 0;
		int n, m, a, b, ans = 0;
		scanf("%d%d", &n, &m);
		while (m--) {
			scanf("%d%d", &a, &b);
			addBiEdge(a, b);
		}
		for (int i = 1; i <= n; i++)
			if (!vis[i])
				ans = max(ans, solve(i));
		printf("%d\n", ans);
	}
	return 0;
}
