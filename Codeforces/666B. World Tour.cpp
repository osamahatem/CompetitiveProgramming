/*
 * 666B. World Tour.cpp
 *
 *  Created on: Apr 29, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

vector<int> adj[3005];
vector<pair<int, int>> from[3005], to[3005];
int dist[3005][3005];

void BFS(int src) {
	queue<int> Q;
	Q.push(src);
	int steps = 0;
	while (Q.size()) {
		int sz = Q.size();
		while (sz--) {
			int cur = Q.front();
			Q.pop();
			dist[src][cur] = steps;
			for (int i = 0; i < (int) adj[cur].size(); i++)
				if (dist[src][adj[cur][i]] == -1)
					Q.push(adj[cur][i]), dist[src][adj[cur][i]] = 0;
		}
		steps++;
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	memset(dist, -1, sizeof dist);
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		adj[u].push_back(v);
	}
	for (int i = 1; i <= n; i++)
		BFS(i);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			if (i == j)
				continue;
			if (dist[i][j] != -1)
				from[i].push_back(make_pair(dist[i][j], j));
			if (dist[j][i] != -1)
				to[i].push_back(make_pair(dist[j][i], j));
			if (from[i].size() > 3) {
				sort(from[i].begin(), from[i].end(), greater<pair<int, int>>());
				from[i].pop_back();
			}
			if (to[i].size() > 3) {
				sort(to[i].begin(), to[i].end(), greater<pair<int, int>>());
				to[i].pop_back();
			}
		}
	int ans = 0, fa = 0, fb = 0, fc = 0, fd = 0;
	for (int b = 1; b <= n; b++)
		for (int c = 1; c <= n; c++) {
			if (b == c || dist[b][c] == -1)
				continue;
			int dbc = dist[b][c];
			for (int i = 0; i < (int) to[b].size(); i++)
				for (int j = 0; j < (int) from[c].size(); j++) {
					int a = to[b][i].second, dab = to[b][i].first;
					int d = from[c][j].second, dcd = from[c][j].first;
					if (a == c || b == d || a == d)
						continue;
					else if (dab + dbc + dcd > ans)
						ans = dab + dbc + dcd, fa = a, fb = b, fc = c, fd = d;
				}
		}
	printf("%d %d %d %d\n", fa, fb, fc, fd);
	return 0;
}
