/*
 * 558D. Guess Your Way Out! II - Segment Tree - Ranking.cpp
 *
 *  Created on: Jul 15, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;

struct qu {
	int ans;
	long long l, r;
};

int tree[16 * MAXN], lazy[16 * MAXN], r = 0;
map<long long, int> rnk;
long long inv_rnk[4 * MAXN];
qu Q[MAXN];

void relax(int n, int s, int e) {
	if (lazy[n] == -1)
		return;
	tree[n] = (e - s + 1) * lazy[n];
	if (s != e)
		lazy[n * 2] = lazy[n * 2 + 1] = lazy[n];
	lazy[n] = -1;
}

int query(int qs, int qe, int n = 1, int s = 0, int e = r - 1) {
	relax(n, s, e);
	if (s > qe || e < qs || qe < qs)
		return 0;
	if (s >= qs && e <= qe)
		return tree[n];
	int mid = (s + e) / 2;
	return query(qs, qe, n * 2, s, mid) + query(qs, qe, n * 2 + 1, mid + 1, e);
}

void update(int qs, int qe, int val, int n = 1, int s = 0, int e = r - 1) {
	relax(n, s, e);
	if (s > qe || e < qs || qe < qs)
		return;
	if (s >= qs && e <= qe) {
		lazy[n] = val;
		relax(n, s, e);
		return;
	}
	int mid = (s + e) / 2;
	update(qs, qe, val, n * 2, s, mid);
	update(qs, qe, val, n * 2 + 1, mid + 1, e);
	tree[n] = tree[n * 2] + tree[n * 2 + 1];
}

void build(int n = 1, int s = 0, int e = r - 1) {
	if (s == e) {
		tree[n] = 1;
		return;
	}
	int mid = (s + e) / 2;
	build(n * 2, s, mid);
	build(n * 2 + 1, mid + 1, e);
	tree[n] = tree[n * 2] + tree[n * 2 + 1];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int h, q, hh;
	scanf("%d%d", &h, &q);
	long long ll = 1ll << (h - 1), rl = (1ll << h) - 1;
	rnk[rl], rnk[ll];
	for (int i = 0; i < q; i++) {
		scanf("%d%I64d%I64d%d", &hh, &Q[i].l, &Q[i].r, &Q[i].ans);
		while (hh < h)
			Q[i].l = Q[i].l * 2, Q[i].r = Q[i].r * 2 + 1, hh++;
		rnk[Q[i].l], rnk[Q[i].r];
		if (Q[i].l > ll)
			rnk[Q[i].l - 1];
		if (Q[i].r < rl)
			rnk[Q[i].r + 1];
	}
	for (map<long long, int>::iterator i = rnk.begin(); i != rnk.end(); i++)
		i->second = r, inv_rnk[r++] = i->first;
	build();
	memset(lazy, -1, sizeof lazy);
	for (int i = 0; i < q; i++) {
		if (!Q[i].ans)
			update(rnk[Q[i].l], rnk[Q[i].r], 0);
		else {
			update(0, rnk[Q[i].l] - 1, 0);
			update(rnk[Q[i].r] + 1, r - 1, 0);
		}
	}
	q = query(0, r - 1);
	if (!q)
		printf("Game cheated!\n");
	else if (q > 1)
		printf("Data not sufficient!\n");
	else {
		for (int i = 0; i < r; i++)
			if (query(i, i))
				printf("%I64d\n", inv_rnk[i]);
	}
	return 0;
}
