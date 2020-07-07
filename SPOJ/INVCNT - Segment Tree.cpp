/*
 * INVCNT - Segment Tree.cpp
 *
 *  Created on: Dec 1, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 2e5 + 5;

int N, arr[MAXN], tree[4 * MAXN];
vector<int> rnk;

int query(int qs, int qe = N - 1, int n = 1, int s = 0, int e = N - 1) {
	if (qs > e || qe < s)
		return 0;
	if (s >= qs && e <= qe)
		return tree[n];
	int mid = (s + e) / 2;
	return query(qs, qe, n * 2, s, mid) + query(qs, qe, n * 2 + 1, mid + 1, e);
}

void update(int tar, int n = 1, int s = 0, int e = N - 1) {
	if (s > tar || e < tar)
		return;
	if (s == e) {
		tree[n]++;
		return;
	}
	int mid = (s + e) / 2;
	update(tar, n * 2, s, mid), update(tar, n * 2 + 1, mid + 1, e);
	tree[n] = tree[n * 2] + tree[n * 2 + 1];
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
		memset(tree, 0, N * 4 * sizeof(int));
		for (int i = 0; i < N; i++) {
			scanf("%d", &arr[i]);
			rnk.push_back(arr[i]);
		}
		sort(rnk.begin(), rnk.end());
		long long res = 0;
		for (int i = 0; i < N; i++) {
			int r = lower_bound(rnk.begin(), rnk.end(), arr[i]) - rnk.begin();
			res += query(r + 1);
			update(r);
		}
		printf("%lld\n", res);
	}
	return 0;
}
