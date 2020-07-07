/*
 * H. Milestones.cpp
 *
 *  Created on: Oct 15, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e4 + 5;
const int MAXQ = 1e5 + 5;

struct node {
	int l, r, ans, id;

	static const bool byL(const node& a, const node& b) {
		return a.l < b.l;
	}

	static const bool byID(const node& a, const node& b) {
		return a.id < b.id;
	}
};

int n, q, arr[MAXN], nxt[MAXN], nxtC[256];
int tree[MAXN];
node Q[MAXQ];

void update(int idx, int v) {
	while (idx < MAXN) {
		tree[idx] += v;
		idx += idx & -idx;
	}
}

int query(int idx) {
	int ret = 0;
	while (idx) {
		ret += tree[idx];
		idx -= idx & -idx;
	}
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++)
		scanf("%d", &arr[i]);
	for (int i = n; i; i--) {
		nxt[i] = nxtC[arr[i]];
		nxtC[arr[i]] = i;
	}
	for (int i = 0; i < 256; i++)
		if (nxtC[i])
			update(nxtC[i], 1);
	for (int i = 0; i < q; i++)
		scanf("%d%d", &Q[i].l, &Q[i].r), Q[i].id = i;
	sort(Q, Q + q, node::byL);
	int cur = 1;
	for (int i = 0; i < q; i++) {
		while (cur < Q[i].l) {
			if (nxt[cur])
				update(nxt[cur], 1);
			cur++;
		}
		Q[i].ans = query(Q[i].r) - query(Q[i].l - 1);
	}
	sort(Q, Q + q, node::byID);
	for (int i = 0; i < q; i++)
		printf("%d\n", Q[i].ans);
	return 0;
}
