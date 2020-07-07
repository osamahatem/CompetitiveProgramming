/*
 * 4472 - Another Crisis.cpp
 *
 *  Created on: Sep 21, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

vector<int> adj[100002];
int N, T;

int solve(int ind) {
	if (adj[ind].size() == 0)
		return 1;
	vector<int> children;
	int req = (adj[ind].size() * T + 99) / 100;
	for (int i = 0; i < (int) adj[ind].size(); i++)
		children.push_back(solve(adj[ind][i]));
	sort(children.begin(), children.end());
	int ret = 0;
	for (int i = 0; i < req; i++)
		ret += children[i];
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	while (scanf("%d %d", &N, &T), N) {
		for (int i = 0; i < N + 1; i++)
			adj[i].clear();
		for (int i = 1; i <= N; i++) {
			int b;
			scanf("%d", &b);
			adj[b].push_back(i);
		}
		printf("%d\n", solve(0));
	}
	return 0;
}
