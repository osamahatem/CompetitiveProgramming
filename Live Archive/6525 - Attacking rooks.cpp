/*
 * 6525 - Attacking rooks.cpp
 *
 *  Created on: Jul 31, 2014
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int N = 1e2 + 5;
const int MAXN = 50 * N;
const int MAXE = MAXN * MAXN;
const int src = 0;
const int snk = MAXE - 1;

int n, R, C, row[MAXN][MAXN], col[MAXN][MAXN];
int head[2 * MAXN], next[MAXE], to[MAXE], cap[MAXE], vis[2 * MAXN], last,
		id = 1;
char grid[N][N];

void addEdge(int f, int t, int c) {
	next[last] = head[f];
	to[last] = t;
	cap[last] = c;
	head[f] = last++;
}

void addAugEdge(int f, int t, int c) {
	addEdge(f, t, c);
	addEdge(t, f, 0);
}

void init() {
	memset(head, -1, sizeof head);
	last = 0;
	++id;

	R = C = 1;
	for (int i = 0; i < n; i++) {
		bool count = 0;
		for (int j = 0; j < n; j++) {
			if (grid[i][j] == '.')
				row[i][j] = R, count = 1;
			else
				R += count, count = 0;
		}
		if (count)
			R++;
	}
	for (int i = 0; i < n; i++) {
		bool count = 0;
		for (int j = 0; j < n; j++) {
			if (grid[j][i] == '.')
				col[j][i] = C, count = 1;
			else
				C += count, count = 0;
		}
		if (count)
			C++;
	}

	for (int i = 1; i <= R; i++)
		addAugEdge(src, i, 1);
	for (int i = 1; i <= C; i++)
		addAugEdge(i + R, snk, 1);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (grid[i][j] == '.')
				addAugEdge(row[i][j], R + col[i][j], 1);
}

bool getPath(int cur) {
	if (cur == snk)
		return true;
	if (vis[cur] == id)
		return false;
	vis[cur] = id;
	for (int i = head[cur]; i != -1; i = next[i])
		if (cap[i] && getPath(to[i])) {
			cap[i]--;
			cap[i ^ 1]++;
			return true;
		}
	return false;
}

int maxFlow() {
	int ans = 0;
	while (getPath(src))
		id++, ans++;
	return ans;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	while (scanf("%d", &n) != EOF) {
		for (int i = 0; i < n; i++)
			scanf("%s", grid[i]);
		init();
		printf("%d\n", maxFlow());
	}
	return 0;
}
