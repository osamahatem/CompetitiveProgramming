/*
 * 739B. Alyona and a tree.cpp
 *
 *  Created on: Nov 23, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 2e5 + 5;
const int LOGN = 18;

int n, arr[MAXN], par[LOGN][MAXN], sum[MAXN];
long long dist[LOGN][MAXN];
vector<int> adj[MAXN];

void solve(int idx) {
	for (int i = 0; i < (int) adj[idx].size(); i++) {
		solve(adj[idx][i]);
		sum[idx] += sum[adj[idx][i]];
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &arr[i]);
	for (int i = 2; i <= n; i++) {
		int p, w;
		scanf("%d%d", &p, &w);
		dist[0][i] = w;
		adj[p].push_back(i), par[0][i] = p;
	}
	for (int j = 1; j < LOGN; j++)
		for (int i = 1; i <= n; i++) {
			dist[j][i] = dist[j - 1][i] + dist[j - 1][par[j - 1][i]];
			par[j][i] = par[j - 1][par[j - 1][i]];
		}
	for (int i = 1; i <= n; i++) {
		sum[par[0][i]]++;
		int u = i;
		for (int j = LOGN - 1; ~j; j--)
			if (dist[j][u] <= arr[i]) {
				arr[i] -= dist[j][u];
				u = par[j][u];
			}
		u = par[0][u];
		sum[u]--;
	}
	solve(1);
	for (int i = 1; i <= n; i++) {
		if (i > 1)
			printf(" ");
		printf("%d", sum[i]);
	}
	printf("\n");
	return 0;
}
