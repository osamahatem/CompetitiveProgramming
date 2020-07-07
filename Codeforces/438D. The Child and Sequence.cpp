/*
 * 438D. The Child and Sequence.cpp
 *
 *  Created on: Feb 28, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;

struct node {
	int maxi;
	long long sum;

	node operator +(const node& rhs) const {
		return node { max(maxi, rhs.maxi), sum + rhs.sum };
	}
};

int N, Q, arr[MAXN];
node tree[4 * MAXN];

void build(int n = 1, int s = 1, int e = N) {
	if (s == e) {
		tree[n] = node { arr[s], arr[s] };
		return;
	}
	int mid = (s + e) / 2;
	build(n * 2, s, mid), build(n * 2 + 1, mid + 1, e);
	tree[n] = tree[n * 2] + tree[n * 2 + 1];
}

long long query(int qs, int qe, int n = 1, int s = 1, int e = N) {
	if (s > qe || e < qs)
		return 0;
	if (s >= qs && e <= qe)
		return tree[n].sum;
	int mid = (s + e) / 2;
	return query(qs, qe, n * 2, s, mid) + query(qs, qe, n * 2 + 1, mid + 1, e);
}

void update(int qs, int qe, int v, bool t, int n = 1, int s = 1, int e = N) {
	if (s > qe || e < qs || (t && v > tree[n].maxi))
		return;
	if (s == e) {
		tree[n].sum = tree[n].maxi = t ? tree[n].sum % v : v;
		return;
	}
	int mid = (s + e) / 2;
	update(qs, qe, v, t, n * 2, s, mid);
	update(qs, qe, v, t, n * 2 + 1, mid + 1, e);
	tree[n] = tree[n * 2] + tree[n * 2 + 1];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	scanf("%d%d", &N, &Q);
	for (int i = 1; i <= N; i++)
		scanf("%d", &arr[i]);
	build();
	while (Q--) {
		int t, l, r;
		scanf("%d%d%d", &t, &l, &r);
		if (t == 1) {
			printf("%lld\n", query(l, r));
		} else if (t == 2) {
			int x;
			scanf("%d", &x);
			update(l, r, x, 1);
		} else {
			update(l, l, r, 0);
		}
	}
	return 0;
}
