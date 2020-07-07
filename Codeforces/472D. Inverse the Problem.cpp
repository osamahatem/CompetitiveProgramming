/*
 * 472D. Inverse the Problem.cpp
 *
 *  Created on: Sep 28, 2014
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int mat[2005][2005], dist[2005];
int head[2005], nxt[4005], to[4005], cost[4005], last = 0;
bool vis[2005];

void addEdge(int f, int t, int c) {
	nxt[last] = head[f];
	to[last] = t;
	cost[last] = c;
	head[f] = last++;
}

void DFS(int n, int c) {
	vis[n] = 1;
	dist[n] = c;
	for (int i = head[n]; i != -1; i = nxt[i])
		if (!vis[to[i]])
			DFS(to[i], c + cost[i]);
}

struct edge {
	int u, v, c;

	const bool operator <(const edge &t) const {
		return c < t.c;
	}
};

struct disjointSet {
	vector<int> root, rank;

	disjointSet(int n) {
		for (int i = 0; i <= n; i++) {
			root.push_back(i);
			rank.push_back(0);
		}
	}

	int find(int n) {
		return (root[n] == n ? root[n] : root[n] = find(root[n]));
	}

	bool merge(int a, int b) {
		int sa = find(a);
		int sb = find(b);
		if (sa == sb)
			return false;
		if (rank[sa] < rank[sb])
			root[sa] = sb;
		else
			root[sb] = sa;
		if (rank[sa] == rank[sb])
			rank[sa]++;
		return true;
	}
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n;
	scanf("%d", &n);
	bool flag = 1;
	vector<edge> all;
	disjointSet DS(n);
	memset(head, -1, sizeof head);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &mat[i][j]);
	for (int i = 0; i < n; i++) {
		if (mat[i][i] != 0) {
			flag = 0;
			goto end;
		}
		for (int j = 0; j < i; j++) {
			if (mat[i][j] != mat[j][i] || mat[i][j] == 0) {
				flag = 0;
				goto end;
			}
			all.push_back(edge { i, j, mat[i][j] });
		}
	}
	sort(all.begin(), all.end());
	for (int i = 0; i < (int) all.size(); i++) {
		int u = all[i].u, v = all[i].v, c = all[i].c;
		if (DS.merge(u, v)) {
			addEdge(u, v, c);
			addEdge(v, u, c);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			vis[j] = 0;
		DFS(i, 0);
		for (int j = 0; j < n; j++)
			if (mat[i][j] != dist[j]) {
				flag = 0;
				goto end;
			}
	}
	end: printf("%s", (flag ? "YES\n" : "NO\n"));
	return 0;
}
