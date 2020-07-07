/*
 * KGSS.cpp
 *
 *  Created on: Dec 5, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;

struct node {
	int m1, m2;

	const node operator +(const node &op) const {
		int nm1 = m1, nm2 = m2;
		if (op.m1 > nm2)
			nm2 = op.m1;
		if (nm2 > nm1)
			swap(nm1, nm2);
		if (op.m2 > nm2)
			nm2 = op.m2;
		if (nm2 > nm1)
			swap(nm1, nm2);
		return node { nm1, nm2 };
	}
};

int N, Q, arr[MAXN];
node tree[4 * MAXN];

void build(int n = 1, int s = 1, int e = N) {
	if (s == e) {
		tree[n] = node { arr[s], 0 };
		return;
	}
	int mid = (s + e) / 2;
	build(n * 2, s, mid), build(n * 2 + 1, mid + 1, e);
	tree[n] = tree[n * 2] + tree[n * 2 + 1];
}

void update(int &tar, int &val, int n = 1, int s = 1, int e = N) {
	if (tar < s || tar > e)
		return;
	if (s == e) {
		tree[n] = node { val, 0 };
		return;
	}
	int mid = (s + e) / 2;
	update(tar, val, n * 2, s, mid), update(tar, val, n * 2 + 1, mid + 1, e);
	tree[n] = tree[n * 2] + tree[n * 2 + 1];
}

node query(int &qs, int &qe, int n = 1, int s = 1, int e = N) {
	if (qe < s || qs > e)
		return node { 0, 0 };
	if (s >= qs && e <= qe)
		return tree[n];
	int mid = (s + e) / 2;
	return query(qs, qe, n * 2, s, mid) + query(qs, qe, n * 2 + 1, mid + 1, e);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d", &arr[i]);
	build();
	scanf("%d", &Q);
	while (Q--) {
		char t;
		int x, y;
		scanf("%*c%c%d%d", &t, &x, &y);
		if (t == 'U')
			update(x, y);
		else {
			node ans = query(x, y);
			printf("%d\n", ans.m1 + ans.m2);
		}
	}
	return 0;
}
