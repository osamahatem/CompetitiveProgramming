/*
 * 10635 - Prince and Princess.cpp
 *
 *  Created on: Aug 19, 2014
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 250 * 250 + 5;

int arr[MAXN], pos[MAXN], dp[MAXN], tree[4 * MAXN];

void update(int n, int s, int e, int &t, int &val) {
	if (e < t || s > t)
		return;
	if (e == s) {
		tree[n] = val;
		return;
	}
	int mid = (s + e) / 2;
	update(n * 2, s, mid, t, val);
	update(n * 2 + 1, mid + 1, e, t, val);
	tree[n] = max(tree[n * 2], tree[n * 2 + 1]);
}

int query(int n, int s, int e, int &qe) {
	if (s > qe)
		return 0;
	if (e <= qe)
		return tree[n];
	int mid = (s + e) / 2;
	int q1 = query(n * 2, s, mid, qe);
	int q2 = query(n * 2 + 1, mid + 1, e, qe);
	return max(q1, q2);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		memset(pos, -1, sizeof pos);
		memset(tree, 0, sizeof tree);
		int n, p, q, x;
		cin >> n >> p >> q;
		for (int i = 0; i <= p; i++) {
			cin >> x;
			pos[x] = i + 1;
		}
		for (int i = 0; i <= q; i++) {
			dp[i] = 1;
			cin >> arr[i];
			int qe = pos[arr[i]] - 1;
			int t = query(1, 0, n * n, qe);
			dp[i] = max(dp[i], t + 1);
			update(1, 0, n * n, pos[arr[i]], dp[i]);
		}
		cout << "Case " << t << ": " << dp[q] << "\n";
	}
	return 0;
}
