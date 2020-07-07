/*
 * BRCKTS.cpp
 *
 *  Created on: Dec 7, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 3e4 + 5;

int N, M, q, arr[MAXN], tree[4 * MAXN], lazy[4 * MAXN];
char in[MAXN];

void build(int n = 1, int s = 1, int e = N) {
	lazy[n] = 0;
	if (s == e) {
		tree[n] = arr[s];
		return;
	}
	int mid = (s + e) / 2;
	build(n * 2, s, mid), build(n * 2 + 1, mid + 1, e);
	tree[n] = min(tree[n * 2], tree[n * 2 + 1]);
}

void relax(int n, int s, int e) {
	tree[n] += lazy[n];
	if (s != e)
		lazy[n * 2] += lazy[n], lazy[n * 2 + 1] += lazy[n];
	lazy[n] = 0;
}

void update(int qs, int qe, int val, int n = 1, int s = 1, int e = N) {
	relax(n, s, e);
	if (qe < s || qs > e)
		return;
	if (s >= qs && e <= qe) {
		lazy[n] += val;
		relax(n, s, e);
		return;
	}
	int mid = (s + e) / 2;
	update(qs, qe, val, n * 2, s, mid);
	update(qs, qe, val, n * 2 + 1, mid + 1, e);
	tree[n] = min(tree[n * 2], tree[n * 2 + 1]);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	for (int t = 1; t <= 10; t++) {
		printf("Test %d:\n", t);
		scanf("%d%s", &N, in);
		for (int i = 1; i <= N; i++)
			arr[i] = arr[i - 1] + (in[i - 1] == '(' ? 1 : -1);
		int sum = arr[N];
		build();
		scanf("%d", &M);
		while (M--) {
			scanf("%d", &q);
			if (q) {
				if (in[q - 1] == '(')
					in[q - 1] = ')', update(q, N, -2), sum -= 2;
				else
					in[q - 1] = '(', update(q, N, 2), sum += 2;
			} else
				printf("%s\n", (tree[1] || sum ? "NO" : "YES"));
		}
	}
	return 0;
}
