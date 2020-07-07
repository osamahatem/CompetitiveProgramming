/*
 * INVCNT - BIT.cpp
 *
 *  Created on: Dec 12, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 2e5 + 5;

int N, arr[MAXN], tree[MAXN];
vector<int> rnk;

void update(int idx, int val) {
	for (; idx <= N; idx += idx & -idx)
		tree[idx] += val;
}

int query(int idx) {
	int ret = 0;
	for (; idx; idx -= idx & -idx)
		ret += tree[idx];
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int t;
	scanf("%d", &t);
	while (t--) {
		rnk.clear();
		scanf("%d", &N);
		memset(tree, 0, sizeof tree);
		for (int i = 0; i < N; i++) {
			scanf("%d", &arr[i]);
			rnk.push_back(arr[i]);
		}
		sort(rnk.begin(), rnk.end());
		long long res = 0;
		for (int i = 0; i < N; i++) {
			int r = lower_bound(rnk.begin(), rnk.end(), arr[i]) - rnk.begin()
					+ 1;
			res += query(N) - query(r - 1);
			update(r, 1);
		}
		printf("%lld\n", res);
	}
	return 0;
}
