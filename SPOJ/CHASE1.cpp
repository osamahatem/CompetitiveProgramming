/*
 * CHASE1.cpp
 *
 *  Created on: May 26, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 3e3 + 5;
const int MAXE = 3e4 + 5;

int head[MAXN], nxt[MAXE], to[MAXE], last;
int idx[MAXN], low[MAXN], id;
bool inCycle[MAXN];
int dist[2][MAXN];

void init() {
	memset(head, -1, sizeof head);
	memset(idx, -1, sizeof idx);
	memset(inCycle, 0, sizeof inCycle);
	memset(dist, 127, sizeof dist);
	last = 0, id = 0;
}

void addEdge(int a, int b) {
	to[last] = b;
	nxt[last] = head[a];
	head[a] = last++;
}

void DFS(int node, int par) {
	idx[node] = low[node] = id++;
	for (int e = head[node]; ~e; e = nxt[e]) {
		if (idx[to[e]] == -1) {
			DFS(to[e], node);
			low[node] = min(low[to[e]], low[node]);
		} else if (to[e] != par) {
			low[node] = min(idx[to[e]], low[node]);
		}
	}
	if (low[node] < idx[node])
		inCycle[node] = 1;
	for (int e = head[node]; ~e && !inCycle[node]; e = nxt[e])
		if (low[node] == idx[node] && low[to[e]] == low[node])
			inCycle[node] = 1;
}

void BFS(int src, int dist[]) {
	queue<int> Q;
	Q.push(src), dist[src] = 0;
	while (Q.size()) {
		int node = Q.front();
		Q.pop();
		for (int e = head[node]; ~e; e = nxt[e])
			if (dist[node] + 1 < dist[to[e]])
				dist[to[e]] = dist[node] + 1, Q.push(to[e]);
	}
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
		int n, m, a, b;
		scanf("%d%d%d%d", &n, &m, &a, &b);
		while (m--) {
			int u, v;
			scanf("%d%d", &u, &v);
			addEdge(u, v), addEdge(v, u);
		}
		DFS(1, -1);
		BFS(a, dist[0]), BFS(b, dist[1]);
		bool win_b = 1;
		for (int i = 1; i <= n; i++)
			if (inCycle[i] && dist[0][i] < dist[1][i])
				win_b = 0;
		if (win_b) {
			int ans = 0;
			for (int i = 1; i <= n; i++)
				if (dist[0][i] < dist[1][i])
					ans = max(ans, dist[1][i]);
			printf("%d\n", ans);
		} else {
			printf("No\n");
		}
	}
	return 0;
}
