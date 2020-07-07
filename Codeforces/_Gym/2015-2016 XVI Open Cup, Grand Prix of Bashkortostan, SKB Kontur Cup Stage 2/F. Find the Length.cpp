/*
 * F. Find the Length.cpp
 *
 *  Created on: Jun 26, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 300;
const int LOGN = 9;

int n, mat[MAXN][MAXN], par[LOGN][MAXN], vis[MAXN], dist[MAXN], depth[MAXN];
vector<pair<int, int>> cycles;

void Dijkstra(int src) {
	cycles.clear();
	memset(par, -1, sizeof par);
	memset(dist, 127, sizeof dist);
	dist[src] = 0, depth[src] = 0;
	for (int i = 0; i < n; i++) {
		int mini = 1 << 30, cur = -1;
		for (int j = 0; j < n; j++)
			if (vis[j] != src && dist[j] < mini)
				mini = dist[j], cur = j;
		vis[cur] = src;
		for (int j = 0; j < n; j++)
			if (mat[cur][j] > 0 && j != par[0][cur]) {
				if (dist[cur] + mat[cur][j] < dist[j]) {
					if (par[0][j] != -1)
						cycles.push_back(make_pair(par[0][j], j));
					par[0][j] = cur;
					dist[j] = dist[cur] + mat[cur][j];
					depth[j] = depth[cur] + 1;
				} else
					cycles.push_back(make_pair(cur, j));
			}
	}
}

void buildLCA() {
	for (int j = 1; j < LOGN; j++)
		for (int i = 0; i < n; i++)
			if (par[j - 1][i] != -1)
				par[j][i] = par[j - 1][par[j - 1][i]];
}

int getLCA(int u, int v) {
	if (depth[u] < depth[v])
		swap(u, v);
	for (int i = LOGN - 1; i >= 0; i--)
		if ((1 << i) & (depth[u] - depth[v]))
			u = par[i][u];
	if (u == v)
		return u;
	for (int i = LOGN - 1; i >= 0; i--)
		if (par[i][u] != par[i][v])
			u = par[i][u], v = par[i][v];
	return par[0][u];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &mat[i][j]);
	memset(vis, -1, sizeof vis);
	for (int nn = 0; nn < n; nn++) {
		Dijkstra(nn);
		buildLCA();
		int ans = 1 << 30;
		for (int i = 0; i < (int) cycles.size(); i++) {
			int u = cycles[i].first, v = cycles[i].second;
			int lca = getLCA(u, v);
			if (lca == nn)
				ans = min(ans, dist[u] + dist[v] + mat[u][v]);
		}
		printf("%d\n", ans == (1 << 30) ? -1 : ans);
	}
	return 0;
}
