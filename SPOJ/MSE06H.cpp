/*
 * MSE06H.cpp
 *
 *  Created on: Dec 7, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1005;

int T, N, M, K, tree[MAXN];

int query(int idx) {
	int ret = 0;
	while (idx > 0) {
		ret += tree[idx];
		idx -= idx & -idx;
	}
	return ret;
}

void update(int idx, int val) {
	while (idx <= M) {
		tree[idx] += val;
		idx += idx & -idx;
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		memset(tree, 0, sizeof tree);
		scanf("%d%d%d", &N, &M, &K);
		vector<pair<int, int>> all(K);
		for (int i = 0; i < K; i++)
			scanf("%d%d", &all[i].first, &all[i].second);
		sort(all.begin(), all.end());
		long long ans = 0;
		for (int i = 0; i < K; i++) {
			ans += query(M) - query(all[i].second);
			update(all[i].second, 1);
		}
		printf("Test case %d: %lld\n", t, ans);
	}
	return 0;
}
