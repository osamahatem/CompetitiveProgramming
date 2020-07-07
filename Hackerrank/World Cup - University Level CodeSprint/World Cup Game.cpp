/*
 * World Cup Game.cpp
 *
 *  Created on: Sep 12, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 5e5 + 5;
const int MAXE = 2 * MAXN;

int head[MAXN], nxt[MAXE], to[MAXE], last;
int par[MAXN];
long long val[MAXN];

void addEdge(int f, int t) {
	to[last] = t;
	nxt[last] = head[f];
	head[f] = last++;
}

void addBiEdge(int f, int t) {
	addEdge(f, t);
	addEdge(t, f);
}

long long dfs(int n) {
	for (int i = head[n]; i != -1; i = nxt[i])
		if (to[i] != par[n]) {
			par[to[i]] = n;
			val[n] += dfs(to[i]);
		}
	return val[n];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	memset(head, -1, sizeof head);
	int n, a, b;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &val[i]);
	for (int i = 1; i < n; i++) {
		scanf("%d%d", &a, &b);
		addBiEdge(a, b);
	}
	dfs(1);
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		long long sec = 0;
		for (int e = head[i]; e != -1; e = nxt[e]) {
			long long tval = (to[e] == par[i] ? val[1] - val[i] : val[to[e]]);
			sec = max(sec, tval);
		}
		ans = max(ans, val[1] - sec);
	}
	printf("%lld\n", ans);
	return 0;
}
