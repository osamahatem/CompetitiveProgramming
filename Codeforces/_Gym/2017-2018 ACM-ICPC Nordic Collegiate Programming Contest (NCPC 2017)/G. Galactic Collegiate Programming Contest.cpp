/*
 * G. Galactic Collegiate Programming Contest.cpp
 *
 *  Created on: Oct 24, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;

int n, m, tree[MAXN], sum[MAXN], cnt[MAXN];
vector<pair<int, int>> rnk, Q;

int getRnk(int a, int b) {
	int idx = lower_bound(rnk.begin(), rnk.end(), make_pair(-a, b))
			- rnk.begin();
	return ++idx;
}

int query(int idx) {
	int ret = 0;
	for (; idx; idx -= idx & -idx)
		ret += tree[idx];
	return ret;
}

void update(int idx, int val) {
	for (; idx < (int) rnk.size(); idx += idx & -idx)
		tree[idx] += val;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		cnt[a]++, sum[a] += b;
		Q.push_back(make_pair(a, b));
		rnk.push_back(make_pair(-cnt[a], sum[a]));
	}
	rnk.push_back(make_pair(0, 0));
	sort(rnk.begin(), rnk.end());
	rnk.erase(unique(rnk.begin(), rnk.end()), rnk.end());
	memset(cnt, 0, sizeof cnt), memset(sum, 0, sizeof sum);
	update((int) rnk.size(), n);
	for (int i = 0; i < m; i++) {
		int a = Q[i].first, b = Q[i].second;
		int r = getRnk(cnt[a], sum[a]);
		update(r, -1);
		cnt[a]++, sum[a] += b;
		r = getRnk(cnt[a], sum[a]);
		update(r, 1);
		r = getRnk(cnt[1], sum[1]);
		printf("%d\n", query(r - 1) + 1);
	}
	return 0;
}
