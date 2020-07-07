/*
 * KQUERY.cpp
 *
 *  Created on: Dec 8, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 3e4 + 5;
const int MAXQ = 2e5 + 5;

struct node {
	int l, r, k, id, ans;

	static const bool byK(const node &a, const node &b) {
		return a.k > b.k;
	}

	static const bool byID(const node &a, const node &b) {
		return a.id < b.id;
	}
};

int N, Q, tree[MAXN];
pair<int, int> arr[MAXN];
node all[MAXQ];

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
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i].first);
		arr[i].second = i + 1;
	}
	sort(arr, arr + N, greater<pair<int, int>>());
	scanf("%d", &Q);
	for (int i = 0; i < Q; i++) {
		scanf("%d%d%d", &all[i].l, &all[i].r, &all[i].k);
		all[i].id = i;
	}
	sort(all, all + Q, node::byK);
	int ptr = 0;
	for (int i = 0; i < Q; i++) {
		while (ptr < N && arr[ptr].first > all[i].k)
			update(arr[ptr++].second, 1);
		all[i].ans = query(all[i].r) - query(all[i].l - 1);
	}
	sort(all, all + Q, node::byID);
	for (int i = 0; i < Q; i++)
		printf("%d\n", all[i].ans);
	return 0;
}
