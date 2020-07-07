/*
 * 230D. Planets.cpp
 *
 *  Created on: Jun 7, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;
const int MAXE = 2 * MAXN;

struct node {
	int id, t;

	const bool operator <(const node &a) const {
		if (t != a.t)
			return t < a.t;
		return id < a.id;
	}
};

int head[MAXN], to[MAXE], cost[MAXE], nxt[MAXE], last = 0;
bool vis[MAXN];
set<int> forb[MAXN];

void addEdge(int f, int t, int c) {
	to[last] = t;
	cost[last] = c;
	nxt[last] = head[f];
	head[f] = last++;
}

void addBiEdge(int f, int t, int c) {
	addEdge(f, t, c);
	addEdge(t, f, c);
}

int dijkstra(int src, int tar) {
	set<node> Q;
	Q.insert(node { 1, 0 });
	while (Q.size()) {
		node cur = *(Q.begin());
		Q.erase(*Q.begin());
		if (cur.id == tar)
			return cur.t;
		if (vis[cur.id])
			continue;
		if (forb[cur.id].count(cur.t)) {
			Q.insert(node { cur.id, cur.t + 1 });
			continue;
		}
		vis[cur.id] = 1;
		for (int i = head[cur.id]; i != -1; i = nxt[i])
			Q.insert(node { to[i], cur.t + cost[i] });
	}
	return -1;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//  freopen("out.out", "w", stdout);
#endif

	memset(head, -1, sizeof head);
	int n, m, f, t, c;
	cin >> n >> m;
	while (m--) {
		cin >> f >> t >> c;
		addBiEdge(f, t, c);
	}
	for (int i = 1; i <= n; i++) {
		int k, x;
		cin >> k;
		while (k--) {
			cin >> x;
			forb[i].insert(x);
		}
	}
	cout << dijkstra(1, n) << endl;
	return 0;
}
