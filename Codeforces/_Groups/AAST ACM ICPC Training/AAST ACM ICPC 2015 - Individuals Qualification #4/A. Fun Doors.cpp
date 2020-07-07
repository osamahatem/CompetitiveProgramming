/*
 * A. Fun Doors.cpp
 *
 *  Created on: Sep 15, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MOD = 1000007;
const int MAXN = 1e5 + 5;

long long fact[MAXN];
int tree[4 * MAXN], N;

void build(int n = 1, int s = 1, int e = N) {
	if (s == e) {
		tree[n] = 1;
		return;
	}
	int mid = (s + e) / 2;
	build(n * 2, s, mid), build(n * 2 + 1, mid + 1, e);
	tree[n] = tree[n * 2] + tree[n * 2 + 1];
}

void update(int q, int n = 1, int s = 1, int e = N) {
	if (q < s || q > e)
		return;
	if (s == e) {
		tree[n] = 0;
		return;
	}
	int mid = (s + e) / 2;
	update(q, n * 2, s, mid), update(q, n * 2 + 1, mid + 1, e);
	tree[n] = tree[n * 2] + tree[n * 2 + 1];
}

int query(int qs, int qe, int n = 1, int s = 1, int e = N) {
	if (qe < s || qs > e)
		return 0;
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

	freopen("doors.in", "r", stdin);
	fact[0] = fact[1] = 1;
	for (int i = 2; i <= 100000; i++)
		fact[i] = fact[i - 1] * i % MOD;
	int T;
	scanf("%d", &T);
	while (T--) {
		long long ans = 0;
		int x, y;
		scanf("%d", &N);
		build();
		for (int i = N - 1; i >= 0; i--) {
			scanf("%d", &x);
			y = query(1, x);
			ans = (ans + fact[i] * --y) % MOD;
			update(x);
		}
		printf("%I64d\n", ++ans);
	}
	return 0;
}
