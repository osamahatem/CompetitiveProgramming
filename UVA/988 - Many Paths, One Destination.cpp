/*
 * 988 - Many Paths, One Destination.cpp
 *
 *  Created on: Sep 18, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int n;
vector<vector<int>> adj;
vector<int> dp;

int solve(int x) {
	if (adj[x].empty())
		return 1;
	int& ret = dp[x];
	if (~ret)
		return ret;
	ret = 0;
	for (int i = 0; i < (int) adj[x].size(); i++)
		ret += solve(adj[x][i]);
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	bool frst = 1;
	while (scanf("%d", &n) != EOF) {
		if (!frst)
			printf("\n");
		for (int i = 0; i < n; i++) {
			int sz;
			scanf("%d", &sz);
			if ((int) adj.size() <= i)
				adj.push_back(vector<int>(sz));
			else
				adj[i].resize(sz);
			for (int j = 0; j < sz; j++)
				scanf("%d", &adj[i][j]);
		}
		dp.assign(n, -1);
		printf("%d\n", solve(0));
		frst = 0;
	}
	return 0;
}
