/*
 * 4976 - Defense Lines.cpp
 *
 *  Created on: Jun 18, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 2e5 + 5;

int n, arr[MAXN], dp[MAXN], tree[4 * MAXN], sz;
vector<int> rnk;

int getRnk(int x) {
	return lower_bound(rnk.begin(), rnk.end(), x) - rnk.begin();
}

int query(int qs, int qe = sz - 1, int n = 1, int s = 0, int e = sz - 1) {
	if (qs > qe || qs > e || qe < s)
		return 0;
	if (s >= qs && e <= qe)
		return tree[n];
	int mid = (s + e) / 2;
	return max(query(qs, qe, n * 2, s, mid),
			query(qs, qe, n * 2 + 1, mid + 1, e));
}

int update(int t, int v, int n = 1, int s = 0, int e = sz - 1) {
	if (t < s || t > e)
		return tree[n];
	if (s == e)
		return tree[n] = max(tree[n], v);
	int mid = (s + e) / 2;
	tree[n] = max(update(t, v, n * 2, s, mid),
			update(t, v, n * 2 + 1, mid + 1, e));
	return tree[n];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int t;
	scanf("%d", &t);
	while (t--) {
		rnk.clear();
		memset(tree, 0, sizeof tree);
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &arr[i]);
			rnk.push_back(arr[i]);
		}
		sort(rnk.begin(), rnk.end());
		rnk.erase(unique(rnk.begin(), rnk.end()), rnk.end());
		sz = (int) rnk.size();
		for (int i = 0; i < n; i++)
			dp[i] = 1 + (i && arr[i - 1] < arr[i] ? dp[i - 1] : 0);
		int ans = 0;
		for (int i = n - 1; ~i; i--) {
			ans = max(ans, dp[i] + query(getRnk(arr[i]) + 1));
			dp[i] = 1 + (i + 1 < n && arr[i + 1] > arr[i] ? dp[i + 1] : 0);
			update(getRnk(arr[i]), dp[i]);
		}
		printf("%d\n", ans);
	}
	return 0;
}
