/*
 * 847J. Students Initiation.cpp
 *
 *  Created on: Sep 28, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 5e3 + 5;
const int MAXV = MAXN + MAXN;
const int MAXE = MAXN * 8;
const int SRC = MAXV - 1;
const int SNK = MAXV - 2;

int n, m;
vector<pair<int, int>> pairs;
int head[MAXV], nxt[MAXE], to[MAXE], cap[MAXE], last;
int Q[MAXV], par[MAXV];

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

void build_graph() {
	memset(head, -1, sizeof head), last = 0;
	for (int i = 1; i <= n; i++)
		addAugEdge(SRC, i, 0);
	for (int i = 0; i < m; i++) {
		addAugEdge(pairs[i].first, n + 1 + i, 1);
		addAugEdge(pairs[i].second, n + 1 + i, 1);
		addAugEdge(n + 1 + i, SNK, 1);
	}
}

bool BFS() {
	memset(par, -1, sizeof par);
	Q[0] = SRC, par[SRC] = 0;
	int qsz = 1;
	for (int i = 0; i < qsz; i++) {
		int cur = Q[i];
		for (int i = head[cur]; ~i; i = nxt[i]) {
			if (par[to[i]] == -1 && cap[i])
				Q[qsz++] = to[i], par[to[i]] = cur;
			if (to[i] == SNK && cap[i])
				return true;
		}
	}
	return false;
}

int DFS(int idx, int lim) {
	if (idx == SNK)
		return lim;
	int f;
	for (int i = head[idx]; ~i; i = nxt[i])
		if (par[to[i]] == idx && (f = DFS(to[i], min(lim, cap[i])))) {
			cap[i] -= f, cap[i ^ 1] += f;
			return f;
		}
	return 0;
}

int dinic() {
	int flow = 0;
	while (BFS())
		flow += DFS(SRC, MAXN);
	return flow;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	scanf("%d%d", &n, &m);
	pairs.resize(m);
	for (int i = 0; i < m; i++)
		scanf("%d%d", &pairs[i].first, &pairs[i].second);
	build_graph();
	int ans = 0, flow = 0;
	while (flow < m) {
		ans++;
		for (int i = head[SRC]; ~i; i = nxt[i])
			cap[i]++;
		flow += dinic();
	}
	printf("%d\n", ans);
	for (int i = 0; i < m; i++) {
		for (int j = head[n + 1 + i]; ~j; j = nxt[j])
			if (to[j] != SNK && cap[j] == 1)
				printf("%d %d\n", to[j],
						pairs[i].first + pairs[i].second - to[j]);
	}
	return 0;
}
