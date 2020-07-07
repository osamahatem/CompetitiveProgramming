/*
 * 317C. Balance.cpp
 *
 *  Created on: Aug 12, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

struct node {
	int a, b, f;
};

int n, v, e, a[300], b[300], vis[300], id;
long long sub[300];
bool adj[300][300];
vector<node> ans;

long long dfs(int nn) {
	vis[nn] = id;
	sub[nn] += max(0, a[nn] - b[nn]);
	for (int i = 0; i < n; i++)
		if (adj[nn][i] && vis[i] != id)
			sub[nn] += dfs(i);
	return sub[nn];
}

void solve(int nn, int d) {
	vis[nn] = id;
	for (int i = 0; d && i < n; i++)
		if (adj[nn][i] && vis[i] != id && sub[i]) {
			int need = min(1ll * d, sub[i]);
			int taken = min(a[i], need);
			ans.push_back(node { i, nn, taken });
			a[i] -= taken, a[nn] += taken;
			solve(i, need), d -= need;
			if (need - taken) {
				ans.push_back(node { i, nn, need - taken });
				a[i] -= need - taken, a[nn] += need - taken;
			}
		}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	scanf("%d%d%d", &n, &v, &e);
	long long suma = 0, sumb = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		suma += a[i];
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &b[i]);
		sumb += b[i];
	}
	if (suma != sumb) {
		printf("NO\n");
		return 0;
	}
	while (e--) {
		int x, y;
		scanf("%d%d", &x, &y);
		x--, y--;
		adj[x][y] = adj[y][x] = 1;
	}
	for (int i = 0; i < n; i++) {
		if (a[i] < b[i]) {
			id++;
			int d = b[i] - a[i];
			memset(sub, 0, sizeof sub);
			if (dfs(i) < d) {
				printf("NO\n");
				return 0;
			}
			id++;
			solve(i, d);
		}
	}
	printf("%d\n", ans.size());
	for (int i = 0; i < (int) ans.size(); i++)
		printf("%d %d %d\n", ++ans[i].a, ++ans[i].b, ans[i].f);
	return 0;
}
