/*
 * 380C. Sereja and Brackets.cpp
 *
 *  Created on: Mar 10, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e6 + 5;

struct node {
	int ans, extraOpen, extraClosed;

	node operator +(const node &rhs) const {
		node ret;
		int extra = min(extraOpen, rhs.extraClosed);
		ret.ans = ans + rhs.ans + 2 * extra;
		ret.extraOpen = extraOpen + rhs.extraOpen - extra;
		ret.extraClosed = extraClosed + rhs.extraClosed - extra;
		return ret;
	}
};

char str[MAXN];
int N, Q;
node tree[4 * MAXN];

void build(int n = 1, int s = 0, int e = N - 1) {
	if (s == e) {
		tree[n] = node { 0, str[s] == '(', str[s] == ')' };
		return;
	}
	int mid = (s + e) / 2;
	build(n * 2, s, mid), build(n * 2 + 1, mid + 1, e);
	tree[n] = tree[n * 2] + tree[n * 2 + 1];
}

node query(int qs, int qe, int n = 1, int s = 0, int e = N - 1) {
	if (s > qe || e < qs)
		return node { 0, 0, 0 };
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

	scanf("%s", str);
	N = strlen(str);
	build();
	scanf("%d", &Q);
	while (Q--) {
		int l, r;
		scanf("%d%d", &l, &r);
		printf("%d\n", query(l - 1, r - 1).ans);
	}
	return 0;
}
