/*
 * 690F1. Tree of Life (easy).cpp
 *
 *  Created on: Jul 10, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e4 + 5;

vector<int> adj[MAXN];

int solve(int n, int d, int p) {
	int ret = d > 1, sz = 0;
	for (int i = 0; i < (int) adj[n].size(); i++)
		if (adj[n][i] != p)
			ret += solve(adj[n][i], d + 1, n), sz++;
	ret += sz * (sz - 1) / 2;
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, a, b;
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	printf("%d\n", solve(1, 0, -1));
	return 0;
}
