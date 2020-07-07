/*
 * 302 - John's trip.cpp
 *
 *  Created on: Aug 20, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 50;
const int MAXE = 2000;

int deg[MAXN];
bool vis[MAXE];
vector<pair<int, int>> adj[MAXN];
vector<int> ans;

void euler(int n) {
	for (int i = 0; i < (int) adj[n].size(); i++)
		if (!vis[adj[n][i].first]) {
			vis[adj[n][i].first] = 1;
			euler(adj[n][i].second);
			ans.push_back(adj[n][i].first);
		}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int x, y, z, s;
	while (scanf("%d%d", &x, &y), x) {
		memset(vis, 0, sizeof vis);
		memset(deg, 0, sizeof deg);
		ans.clear();
		for (int i = 0; i < MAXN; i++)
			adj[i].clear();
		s = min(x, y);
		while (x) {
			scanf("%d", &z);
			adj[x].push_back(make_pair(z, y));
			adj[y].push_back(make_pair(z, x));
			deg[x]++, deg[y]++;
			scanf("%d%d", &x, &y);
		}
		bool invalid = false;
		for (int i = 0; i < MAXN; i++)
			if (deg[i] & 1)
				invalid = true;
		if (invalid) {
			printf("Round trip does not exist.\n\n");
			continue;
		}
		for (int i = 0; i < MAXN; i++)
			sort(adj[i].begin(), adj[i].end());
		euler(s);
		reverse(ans.begin(), ans.end());
		for (int i = 0; i < (int) ans.size(); i++) {
			if (i)
				printf(" ");
			printf("%d", ans[i]);
		}
		printf("\n\n");
	}
	return 0;
}
