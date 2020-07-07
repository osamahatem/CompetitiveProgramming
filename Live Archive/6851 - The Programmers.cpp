/*
 * 6851 - The Programmers.cpp
 *
 *  Created on: Oct 12, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 550;
const int MAXE = 25000;
const int SRC = MAXN - 1;
const int SNK = MAXN - 2;

int head[MAXN], nxt[MAXE], to[MAXE], cap[MAXE], last;
int vis[MAXN], id = 0;

void addEdge(int f, int t, int c) {
	to[last] = t;
	cap[last] = c;
	nxt[last] = head[f];
	head[f] = last++;
}

void addAugEdge(int f, int t, int c) {
	addEdge(f, t, c);
	addEdge(t, f, 0);
}

bool dfs(int n) {
	vis[n] = id;
	for (int i = head[n]; i != -1; i = nxt[i])
		if (cap[i] && vis[to[i]] != id && (to[i] == SNK || dfs(to[i]))) {
			cap[i]--, cap[i ^ 1]++;
			return true;
		}
	return false;
}

int maxFlow() {
	int ans = 0;
	while (id++, dfs(SRC))
		ans++;
	return ans;
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
		int p, s, c, m, a, b;
		scanf("%d%d%d%d", &p, &s, &c, &m);
		for (int i = 0; i < p; i++)
			addAugEdge(SRC, i, 1);
		for (int i = 0; i < s; i++)
			addAugEdge(p + i, SNK, c);
		while (m--) {
			scanf("%d%d", &a, &b);
			a--, b--;
			addAugEdge(a, p + b, 1);
		}
		printf("%d\n", maxFlow());
	}
	return 0;
}
