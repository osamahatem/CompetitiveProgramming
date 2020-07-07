/*
 * D. Fegla Route.cpp
 *
 *  Created on: Sep 6, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 205;
const int MAXM = 2510;
const int SRC = MAXN - 1;
const int SNK = MAXN - 2;
const int INF = 1 << 28;

int head[MAXN], nxt[MAXM], to[MAXM], cap[MAXM], cost[MAXM], last;
int par[MAXN], e[MAXN], dist[MAXN];
bool inQ[MAXN];

void addEdge(int f, int t, int cp, int cst) {
	to[last] = t;
	cap[last] = cp;
	cost[last] = cst;
	nxt[last] = head[f];
	head[f] = last++;
}

void addAugEdge(int f, int t, int cp, int cst) {
	addEdge(f, t, cp, cst);
	addEdge(t, f, 0, -cst);
}

void bellman() {
	memset(inQ, 0, sizeof inQ);
	fill(dist, dist + MAXN, INF);
	queue<int> Q;
	Q.push(SRC), inQ[SRC] = 1, dist[SRC] = 0;
	while (Q.size()) {
		int n = Q.front();
		Q.pop(), inQ[n] = 0;
		for (int i = head[n]; i != -1; i = nxt[i])
			if (cap[i] && dist[n] + cost[i] < dist[to[i]]) {
				par[to[i]] = n, e[to[i]] = i, dist[to[i]] = dist[n] + cost[i];
				if (!inQ[to[i]])
					Q.push(to[i]), inQ[to[i]] = 1;
			}
	}
}

int maxFlow() {
	int ans = 0, mf = 0;
	while (bellman(), dist[SNK] != INF) {
		int n = SNK;
		while (n != SRC) {
			int ee = e[n];
			cap[ee]--, cap[ee ^ 1]++;
			n = par[n];
		}
		mf++, ans += dist[SNK];
	}
	return (mf < 2 ? -1 : ans);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	freopen("feglaroute.in", "r", stdin);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		memset(head, -1, sizeof head), last = 0;
		int n, m, a, b, c;
		cin >> n >> m;
		addAugEdge(SRC, 2, 2, 0);
		addAugEdge(n * 2 + 1, SNK, 2, 0);
		addAugEdge(2, 3, 2, 0);
		addAugEdge(n * 2, n * 2 + 1, 2, 0);
		for (int i = 2; i < n; i++)
			addAugEdge(i * 2, i * 2 + 1, 1, 0);
		while (m--) {
			cin >> a >> b >> c;
			addAugEdge(a * 2 + 1, b * 2, 1, c);
			addAugEdge(b * 2 + 1, a * 2, 1, c);
		}
		cout << "Case " << t << ": " << maxFlow() << endl;
	}
	return 0;
}
