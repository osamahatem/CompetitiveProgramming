/*
 * L. Give Me My Balloon!.cpp
 *
 *  Created on: Sep 1, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 2e3 + 5;

int head[MAXN], nxt[MAXN], to[MAXN], dep[MAXN], col[MAXN], last;
vector<int> need[MAXN], res[MAXN];

void addEdge(int f, int t) {
	nxt[last] = head[f];
	to[last] = t;
	head[f] = last++;
}

void dfs(int n, int p, int d) {
	for (int i = head[n]; i != -1; i = nxt[i])
		if (to[i] != p)
			dfs(to[i], n, d + 1);
	dep[n] = d;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

//	freopen("give.in", "r", stdin);
	int t;
	scanf("%d", &t);
	while (t--) {
		memset(head, -1, sizeof head), last = 0;
		int n, m, ans = 0;
		scanf("%d%d", &n, &m);
		for (int i = 1; i < n; i++) {
			int u, v;
			scanf("%d%d", &u, &v);
			addEdge(u, v), addEdge(v, u);
		}
		dfs(1, 0, 0);
		for (int i = 0; i < MAXN / 2; i++)
			need[i].clear(), res[i].clear();
		for (int i = 2; i <= n; i++) {
			int c;
			scanf("%d", &c);
			need[c].push_back(dep[i]);
		}
		for (int i = 0; i < m; i++)
			scanf("%d", &col[i]);
		for (int i = 0; i < m; i++) {
			int x;
			scanf("%d", &x);
			res[col[i]].push_back(x);
		}
		for (int c = 0; c < MAXN / 2; c++) {
			sort(need[c].begin(), need[c].end());
			sort(res[c].begin(), res[c].end());
			for (int i = 0, j = 0; i < need[c].size() && j < res[c].size();
					i++, j++) {
				if (res[c][j] < need[c][i])
					i--;
				else
					ans++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
