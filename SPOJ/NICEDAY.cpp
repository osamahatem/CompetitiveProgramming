/*
 * NICEDAY.cpp
 *
 *  Created on: Dec 7, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;

int N, tree[MAXN];
pair<int, pair<int, int>> all[MAXN];

void update(int idx, int val) {
	while (idx <= N + 1) {
		tree[idx] = min(tree[idx], val);
		idx += idx & -idx;
	}
}

int query(int idx) {
	int ret = MAXN;
	while (idx > 0) {
		ret = min(ret, tree[idx]);
		idx -= idx & -idx;
	}
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int t, a, b, c;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &N);
		fill(tree, tree + MAXN, MAXN);
		for (int i = 0; i < N; i++) {
			scanf("%d%d%d", &a, &b, &c);
			a++, b++, c++;
			all[i].first = a;
			all[i].second.first = b;
			all[i].second.second = c;
		}
		sort(all, all + N);
		int ans = 0;
		for (int i = 0; i < N; i++) {
			ans += query(all[i].second.first - 1) > all[i].second.second;
			update(all[i].second.first, all[i].second.second);
		}
		printf("%d\n", ans);
	}
	return 0;
}
