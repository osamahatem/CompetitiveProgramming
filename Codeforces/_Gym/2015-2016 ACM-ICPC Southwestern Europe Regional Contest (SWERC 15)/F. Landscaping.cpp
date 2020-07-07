/*
 * F. Landscaping.cpp
 *
 *  Created on: Oct 6, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 55;
const int MAXV = MAXN * MAXN;
const int MAXE = MAXV * 10;
const int SRC = MAXV - 1;
const int SNK = MAXV - 2;

int n, m, a, b;
char grid[55][55];
int dx[] = { 1, -1, 0, 0 }, dy[] = { 0, 0, 1, -1 };
int head[MAXV], nxt[MAXE], to[MAXE], cap[MAXE], last;
int dist[MAXV], Q[MAXV], head_copy[MAXV];

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
	Q[0] = SRC, dist[SRC] = 0;
	int qsz = 1;
	bool ret = false;
	for (int i = 0; i < qsz; i++) {
		int cur = Q[i];
		for (int e = head[cur]; ~e; e = nxt[e]) {
			if (cap[e] && dist[cur] + 1 < dist[to[e]])
				dist[to[e]] = dist[cur] + 1, Q[qsz++] = to[e];
			if (cap[e] && to[e] == SNK)
				ret = true;
		}
	}
	return ret;
}

int DFS(int idx, int lim) {
	if (idx == SNK)
		return lim;
	int f;
	for (int &i = head_copy[idx]; ~i; i = nxt[i]) {
		if (dist[to[i]] == dist[idx] + 1 && cap[i]
				&& (f = DFS(to[i], min(lim, cap[i])))) {
			cap[i] -= f, cap[i ^ 1] += f;
			return f;
		}
	}
	return 0;
}

long long Dinic() {
	long long flow = 0;
	int f;
	while (BFS()) {
		memcpy(head_copy, head, sizeof head);
		while ((f = DFS(SRC, b)))
			flow += f;
	}
	return flow;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	memset(head, -1, sizeof head);
	scanf("%d%d%d%d", &n, &m, &a, &b);
	for (int i = 0; i < n; i++)
		scanf("%s", grid[i]);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (grid[i][j] == '.')
				addAugEdge(SRC, i * n + j, b);
			else
				addAugEdge(i * n + j, SNK, b);
			for (int k = 0; k < 4; k++) {
				int ii = i + dx[k], jj = j + dy[k];
				if (ii < 0 || ii == n || jj < 0 || jj == m)
					continue;
				addAugEdge(i * n + j, ii * n + jj, a);
			}
		}
	}
	printf("%lld\n", Dinic());
	return 0;
}
