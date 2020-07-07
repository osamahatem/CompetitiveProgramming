/*
 * 759C. Nikita and stack.cpp
 *
 *  Created on: Feb 10, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;

int tree[4 * MAXN], lazy[4 * MAXN], arr[MAXN];

void relax(int n, int s, int e) {
	tree[n] += lazy[n];
	if (s != e) {
		lazy[n * 2] += lazy[n];
		lazy[n * 2 + 1] += lazy[n];
	}
	lazy[n] = 0;
}

void update(int qs, int qe, int val, int n, int s, int e) {
	relax(n, s, e);
	if (qe < s || qs > e)
		return;
	if (s >= qs && e <= qe) {
		lazy[n] += val;
		relax(n, s, e);
		return;
	}
	int mid = (s + e) / 2;
	update(qs, qe, val, n * 2, s, mid);
	update(qs, qe, val, n * 2 + 1, mid + 1, e);
	tree[n] = max(tree[n * 2], tree[n * 2 + 1]);
}

int solve(int n, int s, int e) {
	relax(n, s, e);
	if (s == e)
		return tree[n] > 0 ? arr[s] : -1;
	int mid = (s + e) / 2;
	relax(n * 2 + 1, mid + 1, e);
	if (tree[n * 2 + 1] > 0)
		return solve(n * 2 + 1, mid + 1, e);
	return solve(n * 2, s, mid);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int idx, t;
		scanf("%d%d", &idx, &t);
		if (t) {
			int x;
			scanf("%d", &x);
			arr[idx] = x;
			update(1, idx, 1, 1, 1, n);
		} else {
			update(1, idx, -1, 1, 1, n);
		}
		printf("%d\n", solve(1, 1, n));
	}
	return 0;
}
