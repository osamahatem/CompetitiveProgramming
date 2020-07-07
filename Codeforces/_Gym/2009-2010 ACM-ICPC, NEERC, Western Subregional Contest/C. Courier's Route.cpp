/*
 * C. Courier's Route.cpp
 *
 *  Created on: Oct 3, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

vector<pair<int, int>> adj[4005];
bool vis[4005];
vector<int> ans;

void DFS(int n) {
	int c = (n + 3) / 4;
	for (int i = 4 * c - 3; i <= 4 * c; i++) {
		for (auto e : adj[i]) {
			if (!vis[e.second]) {
				vis[e.second] = 1;
				DFS(e.first);
				ans.push_back(e.first);
				ans.push_back(i);
			}
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	freopen("courier.in", "r", stdin);
	freopen("courier.out", "w", stdout);

	int n;
	scanf("%d", &n);
	for (int i = 0; i < 2 * n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		adj[x].push_back(make_pair(y, i));
		adj[y].push_back(make_pair(x, i));
	}
	DFS(1);
	if ((int) ans.size() != 4 * n) {
		printf("No\n");
	} else {
		printf("Yes\n");
		for (int i = 0; i < 4 * n; i++) {
			if (i)
				printf(" ");
			printf("%d", ans[i]);
		}
		printf("\n");
	}
	return 0;
}
