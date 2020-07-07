/*
 * 6957 - Hyacinth.cpp
 *
 *  Created on: Sep 22, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e4 + 5;

int head[MAXN], to[MAXN * 2], nxt[MAXN * 2], last;
int fa[MAXN], fb[MAXN], ff;

void addEdge(int f, int t) {
	to[last] = t;
	nxt[last] = head[f];
	head[f] = last++;
}

void addBiEdge(int f, int t) {
	addEdge(f, t);
	addEdge(t, f);
}

void dfs(int n, int par, int fpar) {
	fa[n] = fpar, fb[n] = ++ff;
	for (int i = head[n]; i != -1; i = nxt[i])
		if (to[i] != par)
			dfs(to[i], n, fb[n]);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, a, b;
	while (scanf("%d", &n) != EOF) {
		memset(head, -1, sizeof head), last = 0;
		for (int i = 1; i < n; i++) {
			scanf("%d%d", &a, &b);
			addBiEdge(a, b);
		}
		fa[1] = 1, fb[1] = 2, ff = 2;
		int cnt = 0;
		for (int i = head[1]; i != -1; i = nxt[i])
			cnt++;
		cnt /= 2;
		for (int i = head[1]; i != -1; i = nxt[i])
			if (cnt)
				dfs(to[i], 1, fa[1]), cnt--;
			else
				dfs(to[i], 1, fb[1]);
		for (int i = 1; i <= n; i++)
			printf("%d %d\n", fa[i], fb[i]);
	}
	return 0;
}
