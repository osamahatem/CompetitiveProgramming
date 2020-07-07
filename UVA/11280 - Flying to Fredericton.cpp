/*
 * 11280 - Flying to Fredericton.cpp
 *
 *  Created on: Sep 15, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int INF = 127 * (1 + (1 << 8) + (1 << 16) + (1 << 24));

int n, m, q, dist[100][100];
map<string, int> rnk;
vector<pair<int, int>> adj[100];
char tmpa[25], tmpb[25];

void bellman() {
	memset(dist, 127, sizeof dist);
	for (int i = 0; i < n; i++)
		dist[i][0] = 0;
	for (int st = 1; st < n; st++) {
		for (int cur = 0; cur < n; cur++) {
			for (int i = 0; i < (int) adj[cur].size(); i++) {
				int to = adj[cur][i].first, cost = adj[cur][i].second;
				if (dist[st - 1][cur] + cost < dist[st][to])
					dist[st][to] = dist[st - 1][cur] + cost;
			}
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		rnk.clear();
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%s", tmpa);
			rnk[tmpa] = i;
			adj[i].clear();
		}
		scanf("%d", &m);
		while (m--) {
			int c;
			scanf("%s%s%d", tmpa, tmpb, &c);
			adj[rnk[tmpa]].push_back( { rnk[tmpb], c });
		}
		bellman();
		scanf("%d", &q);
		printf("Scenario #%d\n", t);
		while (q--) {
			int x;
			scanf("%d", &x);
			x = min(x, n - 2);
			if (dist[x + 1][n - 1] == INF)
				printf("No satisfactory flights\n");
			else
				printf("Total cost of flight(s) is $%d\n", dist[x + 1][n - 1]);
		}
		if (t < T)
			printf("\n");
	}
	return 0;
}
