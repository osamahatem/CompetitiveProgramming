/*
 * 10765 - Doves and bombs.cpp
 *
 *  Created on: Sep 27, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

struct node {
	int idx, val;

	const bool operator <(const node& other) const {
		if (val != other.val)
			return val > other.val;
		return idx < other.idx;
	}
};

int n, m, id;
vector<vector<int>> adj;
vector<int> idx, low;
vector<bool> vis;
vector<node> ans;

void DFS(int cur, int p) {
	idx[cur] = low[cur] = ++id;
	vis[cur] = 1;
	bool art = false;
	int ch = 0, cnt = 0;
	for (int i = 0; i < (int) adj[cur].size(); i++) {
		int to = adj[cur][i];
		if (!vis[to]) {
			DFS(to, cur), ch++;
			low[cur] = min(low[cur], low[to]);
			if ((p == -1 && ch > 1) || (p != -1 && low[to] >= idx[cur]))
				art = true, cnt++;
		} else if (to != p) {
			low[cur] = min(low[cur], idx[to]);
		}
	}
	cnt++;
	ans.push_back( { cur, art ? cnt : 1 });
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	while (scanf("%d%d", &n, &m), n) {
		adj.assign(n, vector<int>());
		int u, v;
		while (scanf("%d%d", &u, &v), u != -1)
			adj[u].push_back(v), adj[v].push_back(u);
		idx.assign(n, 0), low.assign(n, 0), vis.assign(n, 0), id = 0;
		ans.clear();
		DFS(0, -1);
		sort(ans.begin(), ans.end());
		for (int i = 0; i < m; i++)
			printf("%d %d\n", ans[i].idx, ans[i].val);
		printf("\n");
	}
	return 0;
}
