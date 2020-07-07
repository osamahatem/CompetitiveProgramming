/*
 * 567E. President and Roads.cpp
 *
 *  Created on: Aug 6, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;
const long long INF = 1ll << 60;

struct edge {
	int a, b, t;
};

long long dist_to[MAXN], dist_from[MAXN];
int head[MAXN], to[2 * MAXN], cost[2 * MAXN], nxt[2 * MAXN], id[2 * MAXN], last;
bool rev[2 * MAXN], inQ[MAXN], uni[MAXN];
vector<edge> edges;

void addEdge(int f, int t, int c, int _id, bool r) {
	to[last] = t;
	cost[last] = c;
	rev[last] = r;
	nxt[last] = head[f];
	id[last] = _id;
	head[f] = last++;
}

void addBiEdge(int f, int t, int c, int _id) {
	addEdge(f, t, c, _id, 0);
	addEdge(t, f, c, _id, 1);
}

void Dijkstra(int S, long long dist[], bool r) {
	fill(dist, dist + MAXN, INF);
	set<pair<long long, int>> Q;
	Q.insert(make_pair(0, S));
	while (Q.size()) {
		int n = Q.begin()->second;
		long long c = Q.begin()->first;
		Q.erase(Q.begin());
		if (c >= dist[n])
			continue;
		dist[n] = c;
		for (int i = head[n]; i != -1; i = nxt[i])
			if (rev[i] == r)
				Q.insert(make_pair(c + cost[i], to[i]));
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	memset(head, -1, sizeof head);
	int n, m, S, T;
	scanf("%d%d%d%d", &n, &m, &S, &T);
	edges.resize(m);
	for (int i = 0; i < m; i++) {
		scanf("%d%d%d", &edges[i].a, &edges[i].b, &edges[i].t);
		addBiEdge(edges[i].a, edges[i].b, edges[i].t, i);
	}
	Dijkstra(T, dist_from, 1);
	Dijkstra(S, dist_to, 0);
	set<pair<long long, int>> Q;
	Q.insert(make_pair(0, S)), inQ[S] = 1;
	while (Q.size()) {
		int sz = Q.size(), nn = Q.begin()->second, cnt = 0;
		long long dd = Q.begin()->first;
		Q.erase(Q.begin()), inQ[nn] = 0;
		for (int i = head[nn]; i != -1; i = nxt[i])
			if (!rev[i]
					&& dist_to[nn] + cost[i] + dist_from[to[i]] == dist_to[T])
				cnt++;
		for (int i = head[nn]; i != -1; i = nxt[i])
			if (!rev[i]
					&& dist_to[nn] + cost[i] + dist_from[to[i]] == dist_to[T]) {
				if (sz == 1 && cnt == 1)
					uni[id[i]] = 1;
				if (!inQ[to[i]])
					Q.insert(make_pair(dd + cost[i], to[i])), inQ[to[i]] = 1;
			}
	}
	for (int i = 0; i < m; i++) {
		int a = edges[i].a, b = edges[i].b, t = edges[i].t;
		if (dist_to[a] + dist_from[b] == dist_to[T] - t) {
			if (uni[i])
				printf("YES\n");
			else if (t > 1)
				printf("CAN 1\n");
			else
				printf("NO\n");
		} else {
			long long temp = dist_to[a] + dist_from[b] + t - dist_to[T];
			if (temp + 1 < t)
				printf("CAN %I64d\n", temp + 1);
			else
				printf("NO\n");
		}
	}
	return 0;
}
