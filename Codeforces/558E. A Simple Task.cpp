/*
 * 558E. A Simple Task.cpp
 *
 *  Created on: Jul 14, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;

int tree[26][4 * MAXN], lazy[26][4 * MAXN], cnt[26];
char S[MAXN], ans[MAXN];
int N, Q;

void relax(int n, int s, int e, int let) {
	if (lazy[let][n] == -1)
		return;
	tree[let][n] = (e - s + 1) * lazy[let][n];
	if (s != e) {
		lazy[let][n * 2] = lazy[let][n];
		lazy[let][n * 2 + 1] = lazy[let][n];
	}
	lazy[let][n] = -1;
}

void update(int qs, int qe, int let, int val, int n = 1, int s = 0,
		int e = N - 1) {
	relax(n, s, e, let);
	if (s > qe || e < qs || qe < qs)
		return;
	if (s >= qs && e <= qe) {
		lazy[let][n] = val;
		relax(n, s, e, let);
		return;
	}
	int mid = (s + e) / 2;
	update(qs, qe, let, val, n * 2, s, mid);
	update(qs, qe, let, val, n * 2 + 1, mid + 1, e);
	tree[let][n] = tree[let][n * 2] + tree[let][n * 2 + 1];
}

int query(int qs, int qe, int let, int n = 1, int s = 0, int e = N - 1) {
	relax(n, s, e, let);
	if (s > qe || e < qs || qe < qs)
		return 0;
	if (s >= qs && e <= qe)
		return tree[let][n];
	int mid = (s + e) / 2;
	return query(qs, qe, let, n * 2, s, mid)
			+ query(qs, qe, let, n * 2 + 1, mid + 1, e);
}

void build(int n = 1, int s = 0, int e = N - 1) {
	if (s == e) {
		tree[S[s] - 'a'][n]++;
		return;
	}
	int mid = (s + e) / 2;
	build(n * 2, s, mid);
	build(n * 2 + 1, mid + 1, e);
	for (int i = 0; i < 26; i++)
		tree[i][n] = tree[i][n * 2] + tree[i][n * 2 + 1];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int l, r, k;
	scanf("%d%d%s", &N, &Q, S);
	build();
	memset(lazy, -1, sizeof lazy);
	while (Q--) {
		scanf("%d%d%d", &l, &r, &k);
		l--, r--;
		for (int i = 0; i < 26; i++) {
			cnt[i] = query(l, r, i);
			update(l, r, i, 0);
		}
		if (k)
			for (int i = 0; i < 26; i++) {
				update(l, l + cnt[i] - 1, i, 1);
				l += cnt[i];
			}
		else
			for (int i = 25; i >= 0; i--) {
				update(l, l + cnt[i] - 1, i, 1);
				l += cnt[i];
			}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 26; j++)
			if (query(i, i, j)) {
				ans[i] = 'a' + j;
				break;
			}
	}
	ans[N] = '\0';
	printf("%s\n", ans);
	return 0;
}
