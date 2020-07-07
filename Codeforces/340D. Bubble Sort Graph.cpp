/*
 * 340D. Bubble Sort Graph.cpp
 *
 *  Created on: Jan 30, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;

int tree[4 * MAXN];

void update(int n, int s, int e, int t, int v) {
	if (s > t || e < t)
		return;
	if (s == e) {
		tree[n] = v;
		return;
	}
	int m = (s + e) / 2;
	update(n * 2, s, m, t, v);
	update(n * 2 + 1, m + 1, e, t, v);
	tree[n] = max(tree[n * 2], tree[n * 2 + 1]);
}

int query(int n, int s, int e, int qs, int qe) {
	if (s > qe || e < qs)
		return 0;
	if (s >= qs && e <= qe)
		return tree[n];
	int m = (s + e) / 2;
	int q1 = query(n * 2, s, m, qs, qe);
	int q2 = query(n * 2 + 1, m + 1, e, qs, qe);
	return max(q1, q2);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, x, cur, ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		cur = query(1, 0, n, 0, x - 1) + 1;
		ans = max(ans, cur);
		update(1, 0, n, x, cur);
	}
	cout << ans << endl;
	return 0;
}
