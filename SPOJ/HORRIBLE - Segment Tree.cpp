/*
 * HORRIBLE - Segment Tree.cpp
 *
 *  Created on: Dec 3, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;

int N, Q;
long long tree[4 * MAXN], lazy[4 * MAXN];

void relax(int n, int s, int e) {
	tree[n] += lazy[n] * (e - s + 1);
	if (s != e) {
		lazy[n * 2] += lazy[n];
		lazy[n * 2 + 1] += lazy[n];
	}
	lazy[n] = 0;
}

long long query(int &qs, int &qe, int n = 1, int s = 1, int e = N) {
	relax(n, s, e);
	if (qs > e || qe < s)
		return 0;
	if (qs <= s && qe >= e)
		return tree[n];
	int mid = (s + e) / 2;
	return query(qs, qe, n * 2, s, mid) + query(qs, qe, n * 2 + 1, mid + 1, e);
}

void update(int &qs, int &qe, int &v, int n = 1, int s = 1, int e = N) {
	relax(n, s, e);
	if (qs > e || qe < s)
		return;
	if (qs <= s && qe >= e) {
		lazy[n] += v;
		relax(n, s, e);
		return;
	}
	int mid = (s + e) / 2;
	update(qs, qe, v, n * 2, s, mid), update(qs, qe, v, n * 2 + 1, mid + 1, e);
	tree[n] = tree[n * 2] + tree[n * 2 + 1];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif
	int T;
	scanf("%d", &T);
	while (T--) {
		int t, a, b, v;
		scanf("%d%d", &N, &Q);
		memset(tree, 0, N * 4 * sizeof(long long));
		memset(lazy, 0, N * 4 * sizeof(long long));
		while (Q--) {
			scanf("%d%d%d", &t, &a, &b);
			if (t)
				printf("%lld\n", query(a, b));
			else {
				scanf("%d", &v);
				update(a, b, v);
			}
		}
	}
	return 0;
}
