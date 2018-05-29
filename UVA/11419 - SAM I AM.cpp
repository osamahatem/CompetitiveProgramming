/*
 * 11419 - SAM I AM.cpp
 *
 *  Created on: May 29, 2018
 *      Author: Osama Hatem
 */

/*
 * The given grid can be modeled as follows: each row is represented by a node
 * connected to a dummy source, and each column can be represented by a node
 * connected to a dummy sink. Then for each given enemy, we connect its row and
 * column by an edge. All edges in this bipartite graph have a weight/capacity
 * of 1. The answer to the problem is the min cut of that s-t max flow graph.
 * Afterwards, we can get the rows and columns constituting the answer using a
 * simple dfs to get the edges on the cut. All such edges will be connected to
 * either the source or the sink, representing rows and columns respectively.
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 2e3 + 5;
const int MAXE = 2 * (1e6 + MAXN + 5);
const int SRC = MAXN - 1;
const int SNK = MAXN - 2;

int R, C, N;
int head[MAXN], nxt[MAXE], to[MAXE], cap[MAXE], last;
bool vis[MAXN];
int Q[MAXN], par[MAXN], qsz;

void add_edge(int f, int t, int c) {
	to[last] = t;
	cap[last] = c;
	nxt[last] = head[f];
	head[f] = last++;
}

void add_aug_edge(int f, int t, int c) {
	add_edge(f, t, c);
	add_edge(t, f, 0);
}

bool bfs() {
	memset(par, -1, sizeof par);
	Q[0] = SRC, par[SRC] = 0, qsz = 1;
	for (int i = 0; i < qsz; i++) {
		int cur = Q[i];
		for (int i = head[cur]; ~i; i = nxt[i]) {
			if (par[to[i]] == -1 && cap[i])
				par[to[i]] = cur, Q[qsz++] = to[i];
			if (cap[i] && to[i] == SNK)
				return true;
		}
	}
	return false;
}

bool dfs(int idx) {
	if (idx == SNK)
		return true;
	for (int i = head[idx]; ~i; i = nxt[i])
		if (par[to[i]] == idx && dfs(to[i])) {
			cap[i]--, cap[i ^ 1]++;
			return true;
		}
	return false;
}

int max_flow() {
	int flow = 0;
	while (bfs())
		flow += dfs(SRC);
	return flow;
}

void flood_fill(int idx) {
	vis[idx] = true;
	for (int i = head[idx]; ~i; i = nxt[i])
		if (cap[i] && !vis[to[i]])
			flood_fill(to[i]);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	while (cin >> R >> C >> N, R) {
		memset(head, -1, sizeof head), last = 0;
		memset(vis, 0, sizeof vis);

		for (int i = 1; i <= R; i++)
			add_aug_edge(SRC, i, 1);
		for (int i = 1; i <= C; i++)
			add_aug_edge(R + i, SNK, 1);

		while (N--) {
			int r, c;
			cin >> r >> c;
			add_aug_edge(r, R + c, 1);
		}

		cout << max_flow();
		flood_fill(SRC);
		for (int i = head[SRC]; ~i; i = nxt[i])
			if (!vis[to[i]])
				cout << " r" << to[i];
		for (int i = head[SNK]; ~i; i = nxt[i])
			if (vis[to[i]])
				cout << " c" << to[i] - R;
		cout << endl;
	}
	return 0;
}
