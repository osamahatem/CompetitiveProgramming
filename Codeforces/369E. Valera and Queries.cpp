/*
 * 369E. Valera and Queries.cpp
 *
 *  Created on: Apr 15, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 3e5 + 5;
const int MAXP = 1e6 + 5;

int tree[MAXP], last[MAXN], ans[MAXN], pcnt = 0;
pair<int, int> seg[MAXN], Q[MAXN];

int _query(int idx) {
	int ret = 0;
	while (idx) {
		ret += tree[idx];
		idx -= idx & -idx;
	}
	return ret;
}

void _update(int idx, int val) {
	while (idx < MAXP) {
		tree[idx] += val;
		idx += idx & -idx;
	}
}

int query(int l, int r) {
	return _query(r) - (l ? _query(l - 1) : 0);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	memset(last, -1, sizeof last);
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d%d", &seg[i].first, &seg[i].second);
	sort(seg, seg + n);
	for (int i = 0; i < m; i++) {
		int cnt;
		scanf("%d", &cnt);
		while (cnt--) {
			scanf("%d", &Q[pcnt].first);
			Q[pcnt++].second = i;
		}
	}
	sort(Q, Q + pcnt);
	int cur = 0;
	multiset<pair<int, int>> active;
	for (int i = 0; i < pcnt; i++) {
		while (cur < n && seg[cur].first <= Q[i].first) {
			_update(seg[cur].first, 1);
			active.insert(make_pair(seg[cur].second, seg[cur].first));
			cur++;
		}
		while (active.size() && active.begin()->first < Q[i].first) {
			_update(active.begin()->second, -1);
			active.erase(active.begin());
		}
		ans[Q[i].second] += query(last[Q[i].second] + 1, MAXP - 1);
		last[Q[i].second] = Q[i].first;
	}
	for (int i = 0; i < m; i++)
		printf("%d\n", ans[i]);
	return 0;
}
