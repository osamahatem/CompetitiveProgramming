/*
 * 697D. Puzzles.cpp
 *
 *  Created on: Jul 14, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;

vector<int> adj[MAXN];
double ans[MAXN];
int subTree[MAXN];

void solve(int n, int mode) {
	int sz = adj[n].size();
	if (mode == 1) {
		for (int i = 0; i < sz; i++) {
			solve(adj[n][i], mode);
			subTree[n] += subTree[adj[n][i]];
		}
		subTree[n]++;
	} else {
		int sum = 0;
		for (int i = 0; i < sz; i++)
			sum += subTree[adj[n][i]];
		for (int i = 0; i < sz; i++) {
			int ssum = sum - subTree[adj[n][i]];
			ans[adj[n][i]] = ssum / 2.0;
			ans[adj[n][i]] += ans[n] + 1.0;
		}
		for (int i = 0; i < sz; i++)
			solve(adj[n][i], mode);
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, p;
	scanf("%d", &n);
	ans[1] = 1.0;
	for (int i = 2; i <= n; i++) {
		scanf("%d", &p);
		adj[p].push_back(i);
	}
	solve(1, 1);
	solve(1, 2);
	for (int i = 1; i <= n; i++) {
		if (i > 1)
			printf(" ");
		printf("%.9f", ans[i]);
	}
	printf("\n");
	return 0;
}
