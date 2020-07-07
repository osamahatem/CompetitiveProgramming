/*
 * 1930. Ivan's Car.cpp
 *
 *  Created on: Aug 6, 2014
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e4 + 5;
const int MAXE = 2 * (1e5 + 5);

int head[MAXN], to[MAXE], nxt[MAXE], last = 0, src, snk;
bool up[MAXE], vis[MAXN][2];

struct node {
	int idx, c;
	bool t;

	const bool operator <(const node &a) const {
		return c > a.c;
	}
};

void addEdge(int f, int t, bool u) {
	nxt[last] = head[f];
	to[last] = t;
	up[last] = u;
	head[f] = last++;
}

int Dijkstra() {
	priority_queue<node> Q;
	for (int i = head[src]; i != -1; i = nxt[i])
		Q.push(node { to[i], 0, up[i] });
	while (Q.size()) {
		node cur = Q.top();
		Q.pop();
		if (cur.idx == snk)
			return cur.c;
		if (vis[cur.idx][cur.t])
			continue;
		vis[cur.idx][cur.t] = 1;
		for (int i = head[cur.idx]; i != -1; i = nxt[i]) {
			if (vis[to[i]][up[i]])
				continue;
			Q.push(node { to[i], cur.c + (cur.t != up[i]), up[i] });
		}
	}
	return -1;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	memset(head, -1, sizeof head);
	int n, m, f, t;
	scanf("%d%d", &n, &m);
	while (m--) {
		scanf("%d%d", &f, &t);
		addEdge(f, t, 1);
		addEdge(t, f, 0);
	}
	scanf("%d%d", &src, &snk);
	if (src == snk)
		printf("0\n");
	else
		printf("%d\n", Dijkstra());
	return 0;
}
