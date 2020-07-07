/*
 * FASTFLOW.cpp
 *
 *  Created on: Sep 25, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 5e3 + 5;
const int MAXE = 6e4 + 5;
const long long INF = 1ll << 62;

int n, m, SRC, SNK;
int head[MAXN], to[MAXE], nxt[MAXE], last;
long long cap[MAXE];
int vis[MAXN], dist[MAXN], t_head[MAXN], Q[MAXN], qsz, id;

void addEdge(int f, int t, long long c) {
	to[last] = t;
	cap[last] = c;
	nxt[last] = head[f];
	head[f] = last++;
}

bool BFS() {
	id++, qsz = 0;
	dist[SRC] = 0, vis[SRC] = id, Q[qsz++] = SRC;
	for (int i = 0; i < qsz; i++) {
		int cur = Q[i];
		for (int i = head[cur]; i != -1; i = nxt[i]) {
			if (vis[to[i]] != id && cap[i])
				Q[qsz++] = to[i], vis[to[i]] = id, dist[to[i]] = dist[cur] + 1;
			if (cap[i] && to[i] == SNK)
				return true;
		}
	}
	return false;
}

long long DFS(int nn, long long lim) {
	if (nn == SNK)
		return lim;
	long long f;
	for (int& i = t_head[nn]; lim && i != -1; i = nxt[i])
		if (dist[nn] + 1 == dist[to[i]] && cap[i]
				&& (f = DFS(to[i], min(lim, cap[i])))) {
			cap[i] -= f, cap[i ^ 1] += f;
			return f;
		}
	return 0;
}

long long Dinic() {
	long long flow = 0, f;
	while (memcpy(t_head, head, n * sizeof(head[0])), BFS())
		while ((f = DFS(SRC, INF)))
			flow += f;
	return flow;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	scanf("%d%d", &n, &m);
	memset(head, -1, n * sizeof(head[0]));
	SRC = 0, SNK = n - 1;
	while (m--) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		a--, b--;
		addEdge(a, b, c);
		addEdge(b, a, c);
	}
	printf("%lld\n", Dinic());
	return 0;
}
