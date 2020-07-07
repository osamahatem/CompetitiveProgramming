/*
 * A. Promotions.cpp
 *
 *  Created on: Oct 1, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 5e3 + 5;

int a, b, n, e;
vector<int> adj[MAXN], rev[MAXN];
int deg[MAXN];
int vis[MAXN], Q[MAXN], deg_copy[MAXN], id = 0;

int DFS(int idx) {
//	cout << idx << endl;
	vis[idx] = id;
	int ret = 1;
	for (auto ch : rev[idx])
		if (vis[ch] != id)
			ret += DFS(ch);
	return ret;
}

int BFS(int idx) {
	memcpy(deg_copy, deg, sizeof deg);
	int qsz = 0;
	for (int i = 0; i < n; i++)
		if (i != idx && !deg_copy[i])
			Q[qsz++] = i;
	for (int i = 0; i < qsz; i++) {
		int cur = Q[i];
		for (auto ch : adj[cur]) {
			deg_copy[ch]--;
			if (!deg_copy[ch] && ch != idx)
				Q[qsz++] = ch;
		}
	}
	return qsz;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	scanf("%d%d%d%d", &a, &b, &n, &e);
	while (e--) {
		int u, v;
		scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		rev[v].push_back(u);
		deg[v]++;
	}
	int r1 = 0, r2 = 0, r3 = 0;
	for (int i = 0; i < n; i++) {
		id++;
		int early = DFS(i);
		int late = BFS(i) + 1;
		if (late <= a)
			r1++;
		if (late <= b)
			r2++;
		if (early > b)
			r3++;
	}
	printf("%d\n%d\n%d\n", r1, r2, r3);
	return 0;
}
