/*
 * 387E. George and Cards.cpp
 *
 *  Created on: Aug 6, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e6 + 5;

int n, k, pos[MAXN], tree[MAXN];
bool final[MAXN];

void update(int idx, int val) {
	while (idx <= n) {
		tree[idx] += val;
		idx += idx & -idx;
	}
}

int query(int idx) {
	int ret = 0;
	while (idx > 0) {
		ret += tree[idx];
		idx -= idx & -idx;
	}
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		pos[x] = i + 1;
	}
	for (int i = 0; i < k; i++) {
		int x;
		scanf("%d", &x);
		final[x] = 1;
	}
	set<int> lim;
	lim.insert(0), lim.insert(n + 1);
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		auto it = lim.upper_bound(pos[i]);
		int b = *it;
		it--;
		int a = *it;
		if (!final[i]) {
			ans += b - a - 1 - query(b - 1) + query(a);
			update(pos[i], 1);
		} else
			lim.insert(pos[i]);
	}
	printf("%lld\n", ans);
	return 0;
}
