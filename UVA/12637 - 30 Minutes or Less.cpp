/*
 * 12637 - 30 Minutes or Less.cpp
 *
 *  Created on: Aug 14, 2014
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 2e2 + 5;
const int MAXE = MAXN * MAXN;
const int src = MAXN - 1;
const int snk = MAXN - 2;

int head[MAXN], to[MAXE], from[MAXE], cap[MAXE], cost[MAXE], nxt[MAXE], last;
int dist[MAXN], inQ[MAXN], id = 1, path[MAXN];

void init() {
	memset(head, -1, sizeof head);
	last = 0;
}

void addEdge(int f, int t, int ca, int co) {
	nxt[last] = head[f];
	to[last] = t;
	from[last] = f;
	cap[last] = ca;
	cost[last] = co;
	head[f] = last++;
}

void addAugEdge(int f, int t, int ca, int co) {
	addEdge(f, t, ca, co);
	addEdge(t, f, 0, -co);
}

int dst(int x1, int y1, int x2, int y2) {
	return abs(x2 - x1) + abs(y2 - y1);
}

int bellman() {
	for (int i = 0; i < MAXN; i++)
		dist[i] = 1 << 30;
	dist[src] = 0, inQ[src] = id;
	queue<int> Q;
	Q.push(src);
	bool flag = 1;
	for (int j = 0; j < MAXN; j++) {
		int s = Q.size();
		while (s--) {
			int cur = Q.front();
			Q.pop();
			inQ[cur] = 0;
			for (int i = head[cur]; i != -1; i = nxt[i]) {
				int t = to[i], c = dist[cur] + cost[i];
				if (cap[i] && c < dist[t]) {
					if (t == snk)
						flag = 0;
					dist[t] = c;
					path[t] = i;
					if (inQ[t] != id)
						Q.push(t), inQ[t] = id;
				}
			}
		}
		if (Q.empty())
			return (flag ? -1 : dist[snk]);
	}
	return -1;
}

int minCostMaxFlow() {
	int ans = 0, temp;
	while (++id, temp = bellman(), temp != -1) {
		ans += temp;
		for (int i = snk; i != src; i = from[path[i]]) {
			cap[path[i]]--;
			cap[path[i] ^ 1]++;
		}
	}
	return ans;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int R, N, tx, ty;
	pair<int, int> rests[MAXN / 2];
	while (cin >> R >> N) {
		init();
		for (int i = 0; i < R; i++) {
			cin >> rests[i].first >> rests[i].second;
			addAugEdge(src, i, 1, 0);
		}
		for (int i = 0; i < N; i++) {
			cin >> tx >> ty;
			addAugEdge(i + R, snk, 1, 0);
			for (int j = 0; j < R; j++) {
				int x = rests[j].first;
				int y = rests[j].second;
				addAugEdge(j, i + R, 1, dst(x, y, tx, ty));
			}
		}
		cout << minCostMaxFlow() << "\n";
	}
	return 0;
}
