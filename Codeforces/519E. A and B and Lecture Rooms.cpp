/*
 * 519E. A and B and Lecture Rooms.cpp
 *
 *  Created on: Feb 28, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;
const int LOGMAXN = 16;

int N, M, LCA[MAXN][LOGMAXN + 1], par[MAXN], dep[MAXN], size[MAXN];
int vis[MAXN], head[MAXN], to[2 * MAXN], nxt[2 * MAXN], last;

void addEdge(int f, int t) {
	to[last] = t;
	nxt[last] = head[f];
	head[f] = last++;
}

int DFS(int n, int d, int p) {
	vis[n] = 1;
	dep[n] = d, par[n] = p;
	for (int i = head[n]; i != -1; i = nxt[i])
		if (!vis[to[i]])
			size[n] += DFS(to[i], d + 1, n);
	return ++size[n];
}

void init() {
	DFS(0, 0, -1);
	for (int i = 0; i < N; i++)
		LCA[i][0] = par[i];
	for (int j = 1; 1 << j < N; j++)
		for (int i = 0; i < N; i++)
			if (LCA[i][j - 1] != -1)
				LCA[i][j] = LCA[LCA[i][j - 1]][j - 1];
}

int getAncestorAt(int n, int depth) {
	for (int i = LOGMAXN; i >= 0; i--)
		if (dep[n] - (1 << i) >= depth)
			n = LCA[n][i];
	return n;
}

int getLCA(int p, int q) {
	if (dep[p] < dep[q])
		swap(p, q);
	p = getAncestorAt(p, dep[q]);
	if (p == q)
		return p;
	for (int i = LOGMAXN; i >= 0; i--)
		if (LCA[p][i] != -1 && LCA[p][i] != LCA[q][i])
			p = LCA[p][i], q = LCA[q][i];
	return par[p];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	memset(head, -1, sizeof head);
	memset(LCA, -1, sizeof LCA);
	int a, b;
	cin >> N;
	for (int i = 1; i < N; i++) {
		cin >> a >> b;
		a--, b--;
		addEdge(a, b), addEdge(b, a);
	}
	init();
	cin >> M;
	while (M--) {
		cin >> a >> b;
		a--, b--;
		if (a == b) {
			cout << N << endl;
			continue;
		}
		int p = getLCA(a, b), d1 = dep[a] - dep[p], d2 = dep[b] - dep[p], ans;
		if ((d1 + d2) % 2)
			ans = 0;
		else if (d1 == d2) {
			int aa = getAncestorAt(a, dep[p] + 1);
			int bb = getAncestorAt(b, dep[p] + 1);
			ans = N - size[aa] - size[bb];
		} else {
			if (dep[a] < dep[b])
				swap(a, b);
			int p1 = getAncestorAt(a, dep[a] - (d1 + d2) / 2);
			int p2 = getAncestorAt(a, dep[a] - (d1 + d2) / 2 + 1);
			ans = size[p1] - size[p2];
		}
		cout << ans << endl;
	}
	return 0;
}
