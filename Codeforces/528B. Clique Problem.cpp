/*
 * 528B. Clique Problem.cpp
 *
 *  Created on: Mar 17, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int dp[200005], tree[1600005];

void update(int n, int s, int e, int t, int v) {
	if (s > t || e < t)
		return;
	if (s == e) {
		tree[n] = max(tree[n], v);
		return;
	}
	int m = (s + e) / 2;
	update(n * 2, s, m, t, v);
	update(n * 2 + 1, m + 1, e, t, v);
	tree[n] = max(tree[n * 2], tree[n * 2 + 1]);
}

int query(int n, int s, int e, int qe) {
	if (s > qe)
		return 0;
	if (e <= qe)
		return tree[n];
	int m = (s + e) / 2, ret;
	ret = query(n * 2, s, m, qe);
	ret = max(ret, query(n * 2 + 1, m + 1, e, qe));
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	memset(tree, 0, sizeof tree);
	int n, x, w, r = 0, ans = 0;
	set<int> all;
	map<int, int> rnk;
	vector<pair<int, int> > nodes;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x >> w;
		nodes.push_back(make_pair(x - w, x + w));
		all.insert(x - w);
		all.insert(x + w);
	}
	for (set<int>::iterator it = all.begin(); it != all.end(); it++)
		rnk[*it] = r++;
	sort(nodes.begin(), nodes.end());
	for (int i = 0; i < n; i++) {
		nodes[i].first = rnk[nodes[i].first], nodes[i].second =
				rnk[nodes[i].second];
	}
	for (int i = 0; i < n; i++) {
		int temp = query(1, 0, r, nodes[i].first);
		dp[i] = 1 + temp;
		ans = max(dp[i], ans);
		update(1, 0, r, nodes[i].second, dp[i]);
	}
	cout << ans << endl;
	return 0;
}
