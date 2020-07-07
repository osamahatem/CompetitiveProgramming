/*
 * 10557 - XYZZY.cpp
 *
 *  Created on: Sep 15, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int n, energy[101];
vector<int> adj[101];

bool bellman() {
	vector<int> dist(n + 1, INT_MAX), vis(n + 1, 0);
	vector<bool> inQ(n + 1, 0);
	dist[1] = -100, inQ[1] = 1;
	queue<int> Q;
	Q.push(1);
	while (Q.size()) {
		int cur = Q.front();
		Q.pop(), inQ[cur] = 0, vis[cur]++;
		if (vis[cur] > n * 100)
			return false;
		if (cur == n)
			return true;
		for (int i = 0; i < (int) adj[cur].size(); i++) {
			int to = adj[cur][i];
			int cost = dist[cur] + energy[to];
			if (cost < dist[to] && cost < 0) {
				dist[to] = cost;
				if (!inQ[to])
					Q.push(to), inQ[to] = 1;
			}
		}
	}
	return false;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	while (scanf("%d", &n), n != -1) {
		for (int i = 1; i <= n; i++) {
			int nr;
			scanf("%d%d", &energy[i], &nr);
			energy[i] = -energy[i];
			adj[i].resize(nr);
			for (int j = 0; j < nr; j++)
				scanf("%d", &adj[i][j]);
		}
		printf("%s\n", bellman() ? "winnable" : "hopeless");
	}
	return 0;
}
