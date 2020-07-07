/*
 * G. Maximum Islands.cpp
 *
 *  Created on: Oct 13, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 44 * 44;
const int MAXE = MAXN * 10;
const int SRC = MAXN - 1;
const int SNK = MAXN - 2;
const int INF = 1 << 20;

int n, m;
char grid[44][44];
int dx[] = { 1, -1, 0, 0 }, dy[] = { 0, 0, 1, -1 };
int head[MAXN], nxt[MAXE], to[MAXE], cap[MAXE], last;
int dist[MAXN], Q[MAXN], head_copy[MAXN];

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

bool valid(int r, int c, char t) {
	return r >= 0 && r < n && c >= 0 && c < m && grid[r][c] == t;
}

int fixGrid() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!valid(i, j, 'L'))
				continue;
			for (int k = 0; k < 4; k++) {
				int nr = i + dx[k], nc = j + dy[k];
				if (valid(nr, nc, 'C'))
					grid[nr][nc] = 'W';
			}
		}
	}
	int ret = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			ret += grid[i][j] == 'C';
	return ret;
}

void buildGraph() {
	memset(head, -1, sizeof head);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!valid(i, j, 'C'))
				continue;
			if ((i + j) & 1)
				addAugEdge(SRC, i * m + j, 1);
			else {
				addAugEdge(i * m + j, SNK, 1);
				continue;
			}
			for (int k = 0; k < 4; k++) {
				int nr = i + dx[k], nc = j + dy[k];
				if (valid(nr, nc, 'C'))
					addAugEdge(i * m + j, nr * m + nc, 1);
			}
		}
	}
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

int Dinic() {
	int flow = 0;
	int f;
	while (BFS()) {
		memcpy(head_copy, head, sizeof head);
		while ((f = DFS(SRC, INF)))
			flow += f;
	}
	return flow;
}

int countIslands() {
	int ret = 0;
	memset(dist, 0, sizeof dist);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!valid(i, j, 'L') || dist[i * m + j])
				continue;
			ret++;
			dist[i * m + j] = 1, Q[0] = i * m + j;
			int qsz = 1;
			for (int q = 0; q < qsz; q++) {
				int r = Q[q] / m, c = Q[q] % m;
				for (int k = 0; k < 4; k++) {
					int nr = r + dx[k], nc = c + dy[k];
					if (valid(nr, nc, 'L') && !dist[nr * m + nc])
						dist[nr * m + nc] = 1, Q[qsz++] = nr * m + nc;
				}
			}
		}
	}
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%s", grid[i]);
	int clouds = fixGrid();
	buildGraph();
	printf("%d\n", countIslands() + clouds - Dinic());
	return 0;
}
