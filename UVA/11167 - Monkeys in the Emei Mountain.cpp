/*
 * 11167 - Monkeys in the Emei Mountain.cpp
 *
 *  Created on: Oct 21, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXM = 105;
const int MAXT = 5e4 + 5;
const int MAXN = MAXM + MAXT + 5;
const int MAXE = MAXM * MAXT * 2;
const int SRC = MAXN - 1;
const int SNK = MAXN - 2;

int head[MAXN], nxt[MAXE], to[MAXE], cap[MAXE], last;
int headCpy[MAXN];
int dist[MAXN], Q[MAXN], sz;

void init() {
	memset(head, -1, sizeof head);
	last = 0;
}

void addEdge(int u, int v, int c) {
	to[last] = v;
	cap[last] = c;
	nxt[last] = head[u];
	head[u] = last++;
}

void addAugEdge(int u, int v, int c1, int c2 = 0) {
	addEdge(u, v, c1);
	addEdge(v, u, c2);
}

bool BFS() {
	memset(dist, -1, sizeof dist);
	Q[0] = SRC, sz = 1, dist[SRC] = 0;
	for (int i = 0; i < sz; i++) {
		int cur = Q[i];
		for (int i = head[cur]; ~i; i = nxt[i]) {
			if (cap[i] && dist[to[i]] == -1)
				Q[sz++] = to[i], dist[to[i]] = dist[cur] + 1;
			if (cap[i] && to[i] == SNK)
				return true;
		}
	}
	return false;
}

int DFS(int n, int lim) {
	if (n == SNK)
		return lim;
	int f;
	for (int& i = headCpy[n]; ~i; i = nxt[i]) {
		if (dist[n] + 1 == dist[to[i]] && cap[i]
				&& (f = DFS(to[i], min(lim, cap[i])))) {
			cap[i] -= f, cap[i ^ 1] += f;
			return f;
		}
	}
	return 0;
}

int maxFlow() {
	int ret = 0, f;
	while (memcpy(headCpy, head, sizeof head), BFS())
		while ((f = DFS(SRC, 1e9)))
			ret += f;
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, m, T = 0;
	while (scanf("%d%d", &n, &m), n) {
		init();
		int sum = 0;
		for (int i = 0; i < n; i++) {
			int v, a, b;
			scanf("%d%d%d", &v, &a, &b);
			sum += v;
			addAugEdge(SRC, i, v);
			for (int t = a; t < b; t++)
				addAugEdge(i, MAXM + t, 1);
		}
		for (int t = 0; t < MAXT; t++)
			addAugEdge(MAXM + t, SNK, m);
		int ans = maxFlow();
		printf("Case %d: %s\n", ++T, ans == sum ? "Yes" : "No");
		if (ans == sum) {
			for (int i = 0; i < n; i++) {
				vector<int> ts;
				for (int e = head[i]; ~e; e = nxt[e]) {
					if (to[e] != SRC && !cap[e])
						ts.push_back(to[e] - MAXM);
				}
				sort(ts.begin(), ts.end());
				vector<pair<int, int>> out;
				for (int i = 0; i < (int) ts.size(); i++) {
					out.push_back( { ts[i], ts[i] });
					for (i++; i < (int) ts.size() && ts[i] == ts[i - 1] + 1;
							i++)
						;
					i--;
					out.back().second = ts[i] + 1;
				}
				printf("%d", out.size());
				for (int i = 0; i < (int) out.size(); i++)
					printf(" (%d,%d)", out[i].first, out[i].second);
				printf("\n");
			}
		}
	}
	return 0;
}
