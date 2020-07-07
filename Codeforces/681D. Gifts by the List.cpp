/*
 * 681D. Gifts by the List.cpp
 *
 *  Created on: Aug 4, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;

int n, m, target[MAXN];
vector<int> adj[MAXN], ans;
bool isTarget[MAXN], hasParent[MAXN];

bool solve(int idx, int nearestTarget) {
	int newTarget = isTarget[idx] ? idx : nearestTarget;
	if (target[idx] != newTarget)
		return false;
	bool ret = true;
	for (int i = 0; i < (int) adj[idx].size(); i++)
		ret &= solve(adj[idx][i], newTarget);
	if (!ret)
		return false;
	if (target[idx] == idx)
		ans.push_back(idx);
	return true;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	scanf("%d%d", &n, &m);
	while (m--) {
		int p, q;
		scanf("%d%d", &p, &q);
		adj[p].push_back(q), hasParent[q] = 1;
	}
	for (int i = 1; i <= n; i++) {
		int x;
		scanf("%d", &x);
		target[i] = x, isTarget[x] = 1;
	}
	bool solveable = true;
	for (int i = 1; i <= n; i++)
		if (!hasParent[i])
			solveable &= solve(i, 0);
	if (solveable) {
		printf("%d\n", (int) ans.size());
		for (int i = 0; i < (int) ans.size(); i++)
			printf("%d\n", ans[i]);
	} else {
		printf("-1\n");
	}
	return 0;
}
