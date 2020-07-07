/*
 * 12299 - RMQ with Shifts.cpp
 *
 *  Created on: Aug 27, 2014
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;
const int INF = 1 << 20;

int arr[MAXN], tree[4 * MAXN];

void build(int n, int s, int e) {
	if (s == e) {
		tree[n] = arr[s];
		return;
	}
	int mid = (s + e) / 2;
	build(n * 2, s, mid);
	build(n * 2 + 1, mid + 1, e);
	tree[n] = min(tree[n * 2], tree[n * 2 + 1]);
}

void update(int n, int s, int e, int &t, int &v) {
	if (s == e) {
		tree[n] = v;
		return;
	}
	int mid = (s + e) / 2;
	if (t <= mid)
		update(n * 2, s, mid, t, v);
	if (t > mid)
		update(n * 2 + 1, mid + 1, e, t, v);
	tree[n] = min(tree[n * 2], tree[n * 2 + 1]);
}

int query(int n, int s, int e, int &qs, int &qe) {
	if (s >= qs && e <= qe)
		return tree[n];
	int mid = (s + e) / 2;
	int ret = INF;
	if (qs <= mid)
		ret = min(ret, query(n * 2, s, mid, qs, qe));
	if (qe > mid)
		ret = min(ret, query(n * 2 + 1, mid + 1, e, qs, qe));
	return ret;
}

void getIdx(char s[], int idx[], int &sz) {
	int i = 0;
	while (s[i] != '(')
		i++;
	i++;
	int x;
	while (s[i]) {
		x = 0;
		while (s[i] != ',' && s[i] != ')')
			x = x * 10 + s[i] - '0', i++;
		i++;
		idx[sz++] = x;
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, q, idx[15], sz;
	char s[35];
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++)
		scanf("%d", &arr[i]);
	build(1, 1, n);
	while (q--) {
		scanf("%s", s);
		sz = 0;
		getIdx(s, idx, sz);
		if (s[0] == 'q')
			printf("%d\n", query(1, 1, n, idx[0], idx[1]));
		else {
			for (int i = 1; i < sz; i++)
				swap(arr[idx[i]], arr[idx[i - 1]]);
			for (int i = 0; i < sz; i++)
				update(1, 1, n, idx[i], arr[idx[i]]);
		}
	}
	return 0;
}
