/*
 * 11354 - Bond.cpp
 *
 *  Created on: Mar 25, 2018
 *      Author: Osama Hatem
 */

/*
First, we build the MST of the graph so that the only path left between any two
nodes has the lowest value possible for its maximum edge. Now, we build sparse
tables for the parents of each node, and the maximum edges' costs on the path to
those parents, and for each query, we use them to get the highest value edge on
the path between the nodes of the query.
Complexity: O((N + Q) * Log(N))
*/

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 5e4 + 5;
const int LOG = 16;

int n, m, q;
int root[MAXN], rnk[MAXN];
int depth[MAXN], par[LOG][MAXN], maxi[LOG][MAXN];
vector<tuple<int, int, int>> edges;
vector<pair<int, int>> adj[MAXN];

void init() {
	edges.resize(m);
	for (int i = 1; i <= n; i++)
		root[i] = i, rnk[i] = 0, adj[i].clear();
	memset(par, 0, sizeof par);
	memset(maxi, 0, sizeof maxi);
}

int find(int x) {
	return root[x] = (root[x] == x ? x : find(root[x]));
}

bool merge(int x, int y) {
	int a = find(x), b = find(y);
	if (a == b)
		return false;
	if (rnk[a] > rnk[b])
		swap(a, b);
	root[a] = b;
	if (rnk[a] == rnk[b])
		rnk[b]++;
	return true;
}

void build_mst() {
	sort(edges.begin(), edges.end());
	for (int i = 0; i < m; i++) {
		int x = get<1>(edges[i]), y = get<2>(edges[i]), c = get<0>(edges[i]);
		if (merge(x, y)) {
			adj[x].push_back(make_pair(y, c));
			adj[y].push_back(make_pair(x, c));
		}
	}
}

void dfs(int idx, int p, int c, int d) {
	par[0][idx] = p, maxi[0][idx] = c, depth[idx] = d;
	for (int i = 1; i < LOG; i++) {
		par[i][idx] = par[i - 1][par[i - 1][idx]];
		maxi[i][idx] = max(maxi[i - 1][idx], maxi[i - 1][par[i - 1][idx]]);
	}

	for (auto e : adj[idx]) {
		if (e.first != p)
			dfs(e.first, idx, e.second, d + 1);
	}
}

int solve(int x, int y) {
	int ret = 0;

	if (depth[x] > depth[y])
		swap(x, y);

	for (int i = LOG - 1; ~i; i--)
		if (depth[par[i][y]] >= depth[x]) {
			ret = max(ret, maxi[i][y]);
			y = par[i][y];
		}

	if (x == y)
		return ret;

	for (int i = LOG - 1; ~i; i--)
		if (par[i][x] != par[i][y]) {
			ret = max(ret, maxi[i][x]);
			ret = max(ret, maxi[i][y]);
			x = par[i][x], y = par[i][y];
		}
	ret = max(ret, maxi[0][x]);
	ret = max(ret, maxi[0][y]);
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	bool flag = false;
	while (cin >> n >> m) {
		init();

		for (int i = 0; i < m; i++) {
			int x, y, c;
			cin >> x >> y >> c;
			edges[i] = make_tuple(c, x, y);
		}

		build_mst();
		dfs(1, 0, 0, 1);

		if (flag)
			cout << endl;
		flag = true;

		cin >> q;
		while (q--) {
			int x, y;
			cin >> x >> y;
			cout << solve(x, y) << endl;
		}
	}
	return 0;
}
