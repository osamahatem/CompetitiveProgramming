/*
 * 12661 - Funny Car Racing.cpp
 *
 *  Created on: Aug 31, 2014
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 305;
const int MAXE = 5e4 + 5;

int n, m, s, t;
int head[MAXN], to[MAXE], nxt[MAXE], A[MAXE], B[MAXE], cost[MAXE], last;
bool vis[MAXN];

void init() {
	memset(vis, 0, sizeof vis);
	memset(head, -1, sizeof head);
	last = 0;
}

void addEdge(int u, int v, int a, int b, int tm) {
	nxt[last] = head[u];
	to[last] = v;
	A[last] = a;
	B[last] = b;
	cost[last] = tm;
	head[u] = last++;
}

struct node {
	long long tm;
	int id;

	const bool operator <(const node &a) const {
		return tm > a.tm;
	}
};

long long Dijkstra() {
	priority_queue<node> Q;
	Q.push(node { 0, s });
	while (Q.size()) {
		node cur = Q.top();
		Q.pop();
		if (cur.id == t)
			return cur.tm;
		if (vis[cur.id])
			continue;
		vis[cur.id] = 1;
		for (int i = head[cur.id]; i != -1; i = nxt[i]) {
			if (cost[i] > A[i])
				continue;
			int temp = cur.tm % (A[i] + B[i]);
			int nTM;
			if (temp + cost[i] <= A[i])
				nTM = cur.tm + cost[i];
			else
				nTM = cur.tm + cost[i] + A[i] + B[i] - temp;
			if (!vis[to[i]])
				Q.push(node { nTM, to[i] });
		}
	}
	return -1;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int tc = 0, u, v, a, b, tm;
	while (cin >> n >> m >> s >> t) {
		init();
		cout << "Case " << ++tc << ": ";
		while (m--) {
			cin >> u >> v >> a >> b >> tm;
			addEdge(u, v, a, b, tm);
		}
		cout << Dijkstra() << "\n";
	}
	return 0;
}
