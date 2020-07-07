/*
 * 450D. Jzzhu and Cities.cpp
 *
 *  Created on: Jul 1, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;
const int MAXE = 8e5 + 5;
const long long INF = 1ll << 60;

int N, M, K;
int head[MAXN], nxt[MAXE], to[MAXE], cost[MAXE], last = 0;
bool isTrain[MAXE];
long long dist[MAXN];

void addEdge(int f, int t, int c, bool is) {
	to[last] = t;
	cost[last] = c;
	nxt[last] = head[f];
	isTrain[last] = is;
	head[f] = last++;
}

void addBiEdge(int f, int t, int c, bool is) {
	addEdge(f, t, c, is);
	addEdge(t, f, c, is);
}

int Dijkstra() {
	fill(dist, dist + MAXN, INF);
	int used = 0;
	set<pair<pair<long long, int>, bool>> Q;
	Q.insert(make_pair(make_pair(0, 1), 0));
	while (Q.size()) {
		int curN = Q.begin()->first.second;
		long long curD = Q.begin()->first.first;
		bool train = Q.begin()->second;
		Q.erase(Q.begin());
		if (curD >= dist[curN])
			continue;
		if (train)
			used++;
		dist[curN] = curD;
		for (int i = head[curN]; i != -1; i = nxt[i])
			if (curD + cost[i] < dist[to[i]])
				Q.insert(
						make_pair(make_pair(curD + cost[i], to[i]),
								isTrain[i]));
	}
	return used;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	memset(head, -1, sizeof head);
	scanf("%d%d%d", &N, &M, &K);
	int u, v, c;
	while (M--) {
		scanf("%d%d%d", &u, &v, &c);
		addBiEdge(u, v, c, 0);
	}
	for (int i = 0; i < K; i++) {
		scanf("%d%d", &v, &c);
		addBiEdge(1, v, c, 1);
	}
	printf("%d\n", K - Dijkstra());
	return 0;
}
