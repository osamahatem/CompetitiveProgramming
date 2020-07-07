/*
 * 7264 - Kejin Game.cpp
 *
 *  Created on: Sep 25, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e3 + 5;
const int MAXE = 2e4 + 2e3 + 5;
const int SRC = MAXN - 1;
const int SNK = MAXN - 2;
const int INF = 1 << 30;

int head[MAXN], nxt[MAXE], to[MAXE], cap[MAXE], last;
int dist[MAXN], t_head[MAXN];
bool vis[MAXN];

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

bool BFS() {
	memset(vis, 0, sizeof vis);
	memset(dist, 127, sizeof dist);
	queue<int> Q;
	Q.push(SRC), vis[SRC] = 1, dist[SRC] = 0;
	while (Q.size()) {
		int cur = Q.front();
		Q.pop();
		for (int i = head[cur]; i != -1; i = nxt[i]) {
			if (!vis[to[i]] && cap[i]) {
				vis[to[i]] = 1, dist[to[i]] = dist[cur] + 1;
				Q.push(to[i]);
			}
		}
	}
	return vis[SNK];
}

int DFS(int n, int lim) {
	if (n == SNK || !lim)
		return lim;
	int flow = 0, f;
	for (int& i = t_head[n]; lim && i != -1; i = nxt[i])
		if (dist[n] + 1 == dist[to[i]] && (f = DFS(to[i], min(lim, cap[i]))))
			cap[i] -= f, cap[i ^ 1] += f, flow += f, lim -= f;
	return flow;
}

int Dinic() {
	int flow = 0;
	while (BFS()) {
		memcpy(t_head, head, sizeof head);
		flow += DFS(SRC, INF);
	}
	return flow;
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
		int n, m, s;
		scanf("%d%d%d", &n, &m, &s);
		addAugEdge(SRC, s, INF);
		while (m--) {
			int f, t, c;
			scanf("%d%d%d", &t, &f, &c);
			addAugEdge(f + n, t, c);
		}
		for (int i = 1; i <= n; i++) {
			scanf("%d", &m);
			addAugEdge(i + n, SNK, m);
		}
		for (int i = 1; i <= n; i++) {
			scanf("%d", &m);
			addAugEdge(i, i + n, m);
		}
		printf("%d\n", Dinic());
	}
	return 0;
}
