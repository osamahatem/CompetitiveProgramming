/*
 * F. Cosmic timeline.cpp
 *
 *  Created on: Aug 30, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;

struct event {
	long long d;
	int v, t;
};

long long tree[8 * MAXN], dp[MAXN], ans = 0;
event all[MAXN];

long long query(int qs, int qe, int n = 1, int s = 0, int e = 2 * MAXN) {
	if (qs > e || qe < s)
		return 0;
	if (s >= qs && e <= qe)
		return tree[n];
	int mid = (s + e) / 2;
	return max(query(qs, qe, n * 2, s, mid),
			query(qs, qe, n * 2 + 1, mid + 1, e));
}

void update(int q, long long v, int n = 1, int s = 0, int e = 2 * MAXN) {
	if (q > e || q < s)
		return;
	if (s == e) {
		tree[n] = v;
		return;
	}
	int mid = (s + e) / 2;
	update(q, v, n * 2, s, mid), update(q, v, n * 2 + 1, mid + 1, e);
	tree[n] = max(tree[n * 2], tree[n * 2 + 1]);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	memset(tree, 0, sizeof tree);
	int n;
	vector<long long> rnk;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%I64d%d%d", &all[i].d, &all[i].v, &all[i].t);
		rnk.push_back(all[i].d), rnk.push_back(all[i].d - all[i].t);
	}
	sort(rnk.begin(), rnk.end());
	rnk.erase(unique(rnk.begin(), rnk.end()), rnk.end());
	for (int i = 0; i < n; i++) {
		int r = lower_bound(rnk.begin(), rnk.end(), all[i].d) - rnk.begin();
		int rp = lower_bound(rnk.begin(), rnk.end(), all[i].d - all[i].t)
				- rnk.begin();
		dp[i] = query(rp, r) + all[i].v;
		ans = max(ans, dp[i]);
		update(r, dp[i]);
	}
	printf("%I64d\n", ans);
	return 0;
}
