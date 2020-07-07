/*
 * 102D. Buses.cpp
 *
 *  Created on: Feb 9, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 3e5 + 5;
const int MOD = 1e9 + 7;

map<int, int> rnk;
int r = 0, tree[MAXN];

int query(int idx) {
	int ret = 0;
	while (idx > 0) {
		ret = (ret + tree[idx]) % MOD;
		idx -= idx & -idx;
	}
	return ret;
}

void update(int idx, int val) {
	while (idx <= r) {
		tree[idx] = (tree[idx] + val) % MOD;
		idx += idx & -idx;
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, m;
	vector<pair<int, int>> bus;
	scanf("%d%d", &n, &m);
	rnk[n], rnk[0];
	for (int i = 0; i < m; i++) {
		int s, t;
		scanf("%d%d", &s, &t);
		rnk[s], rnk[t];
		bus.push_back(make_pair(t, s));
	}
	sort(bus.begin(), bus.end());
	for (auto it = rnk.begin(); it != rnk.end(); it++)
		it->second = ++r;
	update(rnk[n], 1);
	for (int i = m - 1; i >= 0; i--) {
		int x = query(rnk[bus[i].first]);
		update(rnk[bus[i].first], (MOD - x) % MOD);
		update(rnk[bus[i].second], x);
	}
	printf("%d\n", query(1));
	return 0;
}
