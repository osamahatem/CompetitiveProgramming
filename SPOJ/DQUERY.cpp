/*
 * DQUERY.cpp
 *
 *  Created on: Dec 9, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 3e4 + 5;
const int MAXV = 1e6 + 5;
const int MAXQ = 2e5 + 5;

struct node {
	int l, r, id, ans;

	const bool operator <(const node &a) const {
		return l < a.l;
	}

	static const bool byID(const node &a, const node &b) {
		return a.id < b.id;
	}
};

int N, Q, tree[MAXN], arr[MAXN];
node all[MAXQ];
int last[MAXV], nxt[MAXV];

void update(int idx, int val) {
	while (idx <= N) {
		tree[idx] += val;
		idx += idx & -idx;
	}
}

int query(int idx) {
	int ret = 0;
	while (idx > 0) {
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

	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d", &arr[i]);
	scanf("%d", &Q);
	for (int i = 0; i < Q; i++) {
		scanf("%d%d", &all[i].l, &all[i].r);
		all[i].id = i;
	}
	sort(all, all + Q);
	memset(last, -1, sizeof last);
	for (int i = N; i > 0; i--) {
		nxt[i] = last[arr[i]];
		last[arr[i]] = i;
	}
	for (int i = 1; i < MAXV; i++)
		if (last[i] != -1)
			update(last[i], 1);
	int ptr = 1;
	for (int i = 0; i < Q; i++) {
		while (ptr <= N && ptr < all[i].l) {
			update(ptr, -1);
			if (nxt[ptr] != -1)
				update(nxt[ptr], 1);
			ptr++;
		}
		all[i].ans = query(all[i].r) - query(all[i].l - 1);
	}
	sort(all, all + Q, node::byID);
	for (int i = 0; i < Q; i++)
		printf("%d\n", all[i].ans);
	return 0;
}
