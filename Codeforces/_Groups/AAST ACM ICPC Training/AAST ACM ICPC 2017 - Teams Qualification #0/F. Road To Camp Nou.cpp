#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 5;
const int LOGN = 18;

int tree[MAXN], par[MAXN][LOGN], depth[MAXN];
vector<vector<int>> adj;

int getPar(int x, int d) {
	for (int i = LOGN - 1; ~i; --i) {
		if (depth[x] - (1 << i) >= d)
			x = par[x][i];
	}
	return x;
}

void DFS(int n, int p, int d) {
	depth[n] = d, par[n][0] = p, tree[n] = 1;
	for (auto ch : adj[n]) {
		if (ch == p)
			continue;
		DFS(ch, n, d + 1);
		tree[n] += tree[ch];
	}
}

void build_par(int n) {
	for (int j = 1; j < LOGN; j++)
		for (int i = 1; i <= n; i++)
			par[i][j] = par[par[i][j - 1]][j - 1];
}

int lca(int x, int y) {
	if (depth[y] < depth[x])
		swap(x, y);
	y = getPar(y, depth[x]);
	if (x == y)
		return x;
	for (int i = LOGN - 1; ~i; i--)
		if (par[x][i] != par[y][i])
			x = par[x][i], y = par[y][i];
	return par[x][0];
}

int main () {
	freopen("campnou.in", "r", stdin);
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, q;
		scanf("%d%d", &n, &q);
		adj.clear();
		adj.resize(n + 1);
		for (int i = 2; i <= n; i++) {
			int p;
			scanf("%d", &p);
			adj[p].push_back(i);
			adj[i].push_back(p);
		}
		DFS(1, 0, 0);
		build_par(n);
		while (q--) {
			int x, y;
			scanf("%d%d", &x, &y);
			if (x == y) {
				puts("0");
				continue;
			}
			int l = lca(x, y);
			long long ans;
			//cout << x << " " << y << " " << l << endl;
			//cout <<
			if (l == x || l == y) {
				if (l == y)
					swap(x, y);
				ans = 1ll * tree[y] * (n - tree[getPar(y, depth[x] + 1)]);
			} else
				ans = 1ll * tree[x] * tree[y];
			printf("%lld\n", ans);
		}
	}
	return 0;
}
