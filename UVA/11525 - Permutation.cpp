/*
 * 11525 - Permutation.cpp
 *
 *  Created on: Jun 24, 2018
 *      Author: Osama Hatem
 */

/*
 * Each number provided in the input is the 0-based index of the next element in
 * the permutation, after removing the previously used elements.
 * The problem is now solving queries, where each query is getting the K-th
 * number and removing it from the list. This can be answered in O(log(N)) time
 * using a segment tree.
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 5e4 + 5;

int n, tree[4 * MAXN];

void build(int idx = 1, int s = 1, int e = n) {
	if (s == e) {
		tree[idx] = 1;
		return;
	}
	int mid = (s + e) / 2;
	build(idx * 2, s, mid), build(idx * 2 + 1, mid + 1, e);
	tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
}

int query(int k, int idx = 1, int s = 1, int e = n) {
	if (s == e)
		return s;
	int mid = (s + e) / 2;
	if (tree[idx * 2] > k)
		return query(k, idx * 2, s, mid);
	return query(k - tree[idx * 2], idx * 2 + 1, mid + 1, e);
}

void update(int t, int idx = 1, int s = 1, int e = n) {
	if (t < s || t > e)
		return;
	if (s == e) {
		tree[idx] = 0;
		return;
	}
	int mid = (s + e) / 2;
	update(t, idx * 2, s, mid), update(t, idx * 2 + 1, mid + 1, e);
	tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;
	while (T--) {
		cin >> n;
		build();

		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;

			int ans = query(x);
			if (i)
				cout << " ";
			cout << ans;

			update(ans);
		}
		cout << endl;
	}
	return 0;
}
