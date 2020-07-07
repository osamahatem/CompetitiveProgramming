/*
 * 247 - Calling Circles.cpp
 *
 *  Created on: Sep 17, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int T, n, m, r;
vector<int> adj[25];
map<string, int> rnk;
vector<string> inv_rnk;
char a[30], b[30];
int vis[25], indx[25], lowLink[25], idx;
stack<int> S;
vector<vector<int>> circles;

void SCC(int nn) {
	vis[nn] = 1, S.push(nn), indx[nn] = lowLink[nn] = idx++;
	for (int i = 0; i < (int) adj[nn].size(); i++) {
		int to = adj[nn][i];
		if (!vis[to]) {
			SCC(to);
			lowLink[nn] = min(lowLink[nn], lowLink[to]);
		} else if (vis[to] == 1) {
			lowLink[nn] = min(lowLink[nn], indx[to]);
		}
	}
	if (lowLink[nn] == indx[nn]) {
		vector<int> circle;
		int cur;
		do {
			cur = S.top();
			S.pop(), vis[cur] = 2;
			circle.push_back(cur);
		} while (cur != nn);
		circles.push_back(circle);
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	while (scanf("%d%d", &n, &m), n || m) {
		if (T)
			printf("\n");
		circles.clear();
		rnk.clear(), inv_rnk.clear(), r = 0;
		memset(vis, 0, sizeof vis), idx = 0;
		while (m--) {
			scanf("%s%s", a, b);
			if (!rnk.count(a)) {
				rnk[a] = r;
				inv_rnk.push_back(a);
				adj[r++].clear();
			}
			if (!rnk.count(b)) {
				rnk[b] = r;
				inv_rnk.push_back(b);
				adj[r++].clear();
			}
			adj[rnk[a]].push_back(rnk[b]);
		}
		for (int i = 0; i < r; i++)
			if (!vis[i])
				SCC(i);
		printf("Calling circles for data set %d:\n", ++T);
		for (int i = 0; i < (int) circles.size(); i++) {
			for (int j = 0; j < (int) circles[i].size(); j++) {
				if (j)
					printf(", ");
				printf("%s", inv_rnk[circles[i][j]].c_str());
			}
			printf("\n");
		}
	}
	return 0;
}
