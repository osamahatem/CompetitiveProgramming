/*
 * ROBOTDAG.cpp
 *
 *  Created on: Jun 8, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e4 + 105;
const int MAXE = 2e5 + MAXN;
const int SRC = MAXN - 1;
const int SNK = MAXN - 2;

int N, M, K;
int head[MAXN], nxt[MAXE], to[MAXE], cap[MAXE], last;
int headCopy[MAXN], dist[MAXN];

void init() {
	memset(head, -1, sizeof head);
	last = 0;
}

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
	memset(dist, 127, sizeof dist);
	queue<int> Q;
	Q.push(SRC), dist[SRC] = 0;
	while (Q.size()) {
		int cur = Q.front();
		Q.pop();
		for (int e = head[cur]; ~e; e = nxt[e]) {
			if (cap[e] && dist[cur] + 1 < dist[to[e]])
				Q.push(to[e]), dist[to[e]] = dist[cur] + 1;
			if (cap[e] && to[e] == SNK)
				return true;
		}
	}
	return false;
}

int DFS(int node, int curFlow) {
	if (node == SNK)
		return curFlow;
	int flow = 0;
	for (int &e = headCopy[node]; ~e; e = nxt[e])
		if (cap[e] && dist[node] + 1 == dist[to[e]]) {
			int temp = DFS(to[e], min(curFlow, cap[e]));
			cap[e] -= temp, cap[e ^ 1] += temp;
			flow += temp;
		}
	return flow;
}

int Dinic() {
	int flow = 0;
	while (memcpy(headCopy, head, sizeof head), BFS())
		flow += DFS(SRC, K);
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
		init();
		scanf("%d%d%d", &N, &M, &K);
		while (M--) {
			int u, v;
			scanf("%d%d", &u, &v);
			u--, v--;
			for (int i = 0; i < N; i++)
				addAugEdge(u * N + i, v * N + i + 1, 1);
		}
		addAugEdge(SRC, 0, K);
		int cnt = 0, ans = 0;
		while (cnt < K && ans < N) {
			ans++;
			addAugEdge((N - 1) * N + ans, SNK, K);
			cnt += Dinic();
		}
		printf("%d\n", cnt == K ? ans : -1);
	}
	return 0;
}
