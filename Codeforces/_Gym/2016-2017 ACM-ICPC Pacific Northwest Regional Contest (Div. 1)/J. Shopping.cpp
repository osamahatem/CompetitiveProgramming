/*
 * J. Shopping.cpp
 *
 *  Created on: Oct 11, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 2e5 + 5;

int n, q;
long long arr[MAXN], tree[MAXN * 4];

long long build(int idx = 1, int s = 0, int e = n - 1) {
	if (s == e)
		return tree[idx] = arr[s];
	int mid = (s + e) / 2;
	return tree[idx] = min(build(idx * 2, s, mid),
			build(idx * 2 + 1, mid + 1, e));
}

void query(long long& v, int l, int r, int idx = 1, int s = 0, int e = n - 1) {
	if (l > e || r < s || tree[idx] > v)
		return;
	if (s == e) {
		v %= tree[idx];
		return;
	}
	int mid = (s + e) / 2;
	query(v, l, r, idx * 2, s, mid);
	query(v, l, r, idx * 2 + 1, mid + 1, e);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	scanf("%d%d", &n, &q);
	for (int i = 0; i < n; i++)
		scanf("%lld", &arr[i]);
	build();
	while (q--) {
		long long v;
		int l, r;
		scanf("%lld%d%d", &v, &l, &r);
		l--, r--;
		query(v, l, r);
		printf("%lld\n", v);
	}
	return 0;
}
