/*
 * 833B. The Bakery.cpp
 *
 *  Created on: Jun 8, 2018
 *      Author: Osama Hatem
 */

/*
 * http://codeforces.com/blog/entry/53567
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 35e3 + 5;

int n, k, arr[MAXN], nxt[MAXN], last[MAXN];
int tree[2][MAXN * 4], lazy[2][MAXN * 4];

void relax(int tree[], int lazy[], int idx, int s, int e) {
	tree[idx] += lazy[idx];
	if (s != e)
		lazy[idx * 2] += lazy[idx], lazy[idx * 2 + 1] += lazy[idx];
	lazy[idx] = 0;
}

void update(int tree[], int lazy[], int v, int qs, int qe, int idx = 1, int s =
		0, int e = n) {
	if (lazy[idx])
		relax(tree, lazy, idx, s, e);
	if (qs > e || qe < s)
		return;
	if (s >= qs && e <= qe) {
		lazy[idx] += v;
		relax(tree, lazy, idx, s, e);
		return;
	}
	int mid = (s + e) / 2;
	update(tree, lazy, v, qs, qe, idx * 2, s, mid);
	update(tree, lazy, v, qs, qe, idx * 2 + 1, mid + 1, e);
	tree[idx] = max(tree[idx * 2], tree[idx * 2 + 1]);
}

int query(int tree[], int lazy[], int qs, int qe, int idx = 1, int s = 0,
		int e = n) {
	if (lazy[idx])
		relax(tree, lazy, idx, s, e);
	if (qs > e || qe < s)
		return 0;
	if (s >= qs && e <= qe)
		return tree[idx];
	int mid = (s + e) / 2;
	int ret = max(query(tree, lazy, qs, qe, idx * 2, s, mid),
			query(tree, lazy, qs, qe, idx * 2 + 1, mid + 1, e));
	tree[idx] = max(tree[idx * 2], tree[idx * 2 + 1]);
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		last[arr[i]] = n;
	}

	for (int i = n - 1; ~i; i--) {
		nxt[i] = last[arr[i]];
		last[arr[i]] = i;
	}

	for (int j = 1; j <= k; j++) {
		memcpy(tree[1], tree[0], sizeof tree[0]);
		memcpy(lazy[1], lazy[0], sizeof lazy[0]);
		memset(tree[0], 0, sizeof tree[0]);
		memset(lazy[0], 0, sizeof lazy[0]);
		for (int i = n - 1; ~i; i--) {
			update(tree[1], lazy[1], 1, i + 1, nxt[i]);
			int temp = query(tree[1], lazy[1], i + 1, n);
			update(tree[0], lazy[0], temp, i, i);
		}
	}
	cout << query(tree[0], lazy[0], 0, 0) << endl;
	return 0;
}
