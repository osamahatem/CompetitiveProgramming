/*
 * FREQUENT.cpp
 *
 *  Created on: Dec 6, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;
const int INF = 1 << 28;

struct node {
	int rep, val, lrep, lval, rrep, rval;

	const node operator +(const node &op) const {
		node ret;
		ret.rep = rep, ret.val = val;
		if (op.rep > ret.rep)
			ret.rep = op.rep, ret.val = op.val;
		if (rval == op.lval && rrep + op.lrep > ret.rep)
			ret.rep = rrep + op.lrep, ret.val = rval;
		ret.lval = lval, ret.lrep = lrep, ret.rval = op.rval, ret.rrep = op.rrep;
		if (ret.lval == op.lval)
			ret.lrep += op.lrep;
		if (ret.rval == rval)
			ret.rrep += rrep;
		return ret;
	}
};

int N, Q, arr[MAXN];
node tree[4 * MAXN];

void build(int n = 1, int s = 1, int e = N) {
	if (s == e) {
		tree[n] = node { 1, arr[s], 1, arr[s], 1, arr[s] };
		return;
	}
	int mid = (s + e) / 2;
	build(n * 2, s, mid), build(n * 2 + 1, mid + 1, e);
	tree[n] = tree[n * 2] + tree[n * 2 + 1];
}

node query(int &qs, int &qe, int n = 1, int s = 1, int e = N) {
	if (qe < s || qs > e)
		return node { 0, -INF, 0, -INF, 0, -INF };
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

	while (scanf("%d", &N), N) {
		scanf("%d", &Q);
		for (int i = 1; i <= N; i++)
			scanf("%d", &arr[i]);
		build();
		while (Q--) {
			int x, y;
			scanf("%d%d", &x, &y);
			printf("%d\n", query(x, y).rep);
		}
	}
	return 0;
}
