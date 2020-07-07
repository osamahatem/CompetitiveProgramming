/*
 * 540E. Infinite Inversions.cpp
 *
 *  Created on: Apr 30, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;

int tree[8 * MAXN];

void build() {
	memset(tree, 0, sizeof tree);
}

int query(int n, int s, int e, int qs, int qe) {
	if (s > qe || e < qs)
		return 0;
	if (s >= qs && e <= qe)
		return tree[n];
	int m = (s + e) / 2;
	int ret = query(n * 2, s, m, qs, qe);
	ret += query(n * 2 + 1, m + 1, e, qs, qe);
	return ret;
}

void update(int n, int s, int e, int t) {
	if (s > t || e < t)
		return;
	if (s == e && s == t) {
		tree[n]++;
		return;
	}
	int m = (s + e) / 2;
	update(n * 2, s, m, t);
	update(n * 2 + 1, m + 1, e, t);
	tree[n] = tree[n * 2] + tree[n * 2 + 1];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, r = 1, arr[2 * MAXN];
	cin >> n;
	vector<pair<int, int> > swaps(n);
	set<int> all;
	map<int, int> rnk, inv_rnk;
	for (int i = 0; i < n; i++) {
		cin >> swaps[i].first >> swaps[i].second;
		all.insert(swaps[i].first);
		all.insert(swaps[i].second);
	}
	for (set<int>::iterator it = all.begin(); it != all.end(); it++) {
		rnk[*it] = r, inv_rnk[r] = *it;
		r++;
	}
	for (int i = 1; i < r; i++)
		arr[i] = i;
	for (int i = 0; i < n; i++)
		swap(arr[rnk[swaps[i].first]], arr[rnk[swaps[i].second]]);
	build();
	long long ans = 0;
	for (int i = 1; i < r; i++) {
		int bigger = query(1, 0, r, arr[i] + 1, r);
		ans += bigger;
		if (arr[i] < i)
			ans += inv_rnk[i] - i - inv_rnk[arr[i]] + arr[i];
		if (arr[i] > i)
			ans += inv_rnk[arr[i]] - arr[i] - inv_rnk[i] + i;
		update(1, 0, r, arr[i]);
	}
	cout << ans << endl;
	return 0;
}
