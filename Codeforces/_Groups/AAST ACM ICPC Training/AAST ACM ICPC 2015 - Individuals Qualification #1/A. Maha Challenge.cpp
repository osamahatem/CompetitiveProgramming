/*
 * A. Maha Challenge.cpp
 *
 *  Created on: Sep 6, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1005;
const int MAXE = 4005;

int head[MAXN], to[MAXE], from[MAXE], nxt[MAXE], cost[MAXE], id[MAXE], last;
bool inv[MAXE];
int target, remE;

void addEdge(int f, int t, int cst, int _id) {
	to[last] = t;
	from[last] = f;
	cost[last] = cst;
	id[last] = _id;
	nxt[last] = head[f];
	head[f] = last++;
}

void addBiEdge(int f, int t, int cst, int _id) {
	addEdge(f, t, cst, _id);
	addEdge(t, f, cst, _id);
}

void dfs(int n, int par, int maxE) {
	if (n == target) {
		remE = (remE == -1 || cost[maxE] > cost[remE] ? maxE : remE);
		return;
	}
	for (int i = head[n]; i != -1; i = nxt[i])
		if (!inv[id[i]] && to[i] != par)
			dfs(to[i], n, maxE == -1 || cost[i] > cost[maxE] ? i : maxE);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	freopen("mahachallenge.in", "r", stdin);
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		memset(head, -1, sizeof head), last = 0;
		memset(inv, 0, sizeof inv);
		int n, q, a, b, c;
		scanf("%d", &n);
		for (int i = 1; i < n; i++) {
			scanf("%d%d%d", &a, &b, &c);
			addBiEdge(a, b, c, i);
		}
		scanf("%d", &q);
		for (int i = 0; i < q; i++) {
			scanf("%d%d%d", &a, &b, &c);
			addBiEdge(a, b, c, n + i);
			target = b, remE = -1;
			dfs(a, -1, -1);
			inv[id[remE]] = 1;
			a = to[remE], b = from[remE], c = cost[remE];
			if (a > b)
				swap(a, b);
			printf("Case %d-%d: %d %d %d\n", t, i + 1, a, b, c);
		}
	}
	return 0;
}
