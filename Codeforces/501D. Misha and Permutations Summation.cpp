/*
 * 501D. Misha and Permutations Summation.cpp
 *
 *  Created on: Jun 7, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 2e5 + 5;

int N, tree[4 * MAXN], coeff[MAXN];

void build() {
	memset(tree, 0, sizeof tree);
}

void update(int n, int s, int e, int q, int v) {
	if (q > e || q < s)
		return;
	if (s >= q && e <= q) {
		tree[n] += v;
		return;
	}
	int m = (s + e) / 2;
	update(n * 2, s, m, q, v);
	update(n * 2 + 1, m + 1, e, q, v);
	tree[n] = tree[n * 2] + tree[n * 2 + 1];
}

int query(int n, int s, int e, int qs, int qe) {
	if (qs > e || qe < s)
		return 0;
	if (s >= qs && e <= qe)
		return tree[n];
	int m = (s + e) / 2, ret = 0;
	ret += query(n * 2, s, m, qs, qe);
	ret += query(n * 2 + 1, m + 1, e, qs, qe);
	return ret;
}

int getIth(int idx) {
	int cn = 1, s = 0, e = N - 1;
	while (s != e) {
		int m = (s + e) / 2;
		int k = m - s + 1 - tree[cn * 2];
		if (k > idx)
			e = m, cn *= 2;
		else
			s = m + 1, idx -= k, cn = cn * 2 + 1;
	}
	return s;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, x;
	cin >> n;
	N = n;
	build();
	for (int i = 0; i < n; i++) {
		cin >> x;
		coeff[n - i - 1] += x + query(1, 0, n - 1, 0, x);
		update(1, 0, n - 1, x, -1);
	}
	build();
	for (int i = 0; i < n; i++) {
		cin >> x;
		coeff[n - i - 1] += x + query(1, 0, n - 1, 0, x);
		update(1, 0, n - 1, x, -1);
	}
	for (int i = 0; i < n; i++) {
		coeff[i + 1] += coeff[i] / (i + 1);
		coeff[i] %= i + 1;
	}
	build();
	for (int i = n - 1; i >= 0; i--) {
		int val = getIth(coeff[i]);
		cout << val;
		update(1, 0, n - 1, val, 1);
		if (i)
			cout << " ";
	}
	cout << endl;
	return 0;
}
