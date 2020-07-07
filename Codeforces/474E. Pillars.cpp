/*
 * 474E. Pillars.cpp
 *
 *  Created on: Apr 14, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;

pair<int, int> tree[12 * MAXN];
vector<long long> rnk;
int n, d, ans[MAXN], prv[MAXN];
long long in[MAXN];

int getRnk(long long x) {
	return lower_bound(rnk.begin(), rnk.end(), x) - rnk.begin();
}

void build(int n = 1, int s = 0, int e = (int) rnk.size() - 1) {
	if (s == e) {
		tree[n] = make_pair(0, -1);
		return;
	}
	int mid = (s + e) / 2;
	build(n * 2, s, mid), build(n * 2 + 1, mid + 1, e);
	tree[n] = max(tree[n * 2], tree[n * 2 + 1]);
}

pair<int, int> query(int qs, int qe, int n = 1, int s = 0,
		int e = (int) rnk.size() - 1) {
	if (qs > e || qe < s)
		return make_pair(0, -1);
	if (qs <= s && qe >= e)
		return tree[n];
	int mid = (s + e) / 2;
	return max(query(qs, qe, n * 2, s, mid),
			query(qs, qe, n * 2 + 1, mid + 1, e));
}

void update(int t, int v, int idx, int n = 1, int s = 0,
		int e = (int) rnk.size() - 1) {
	if (t > e || t < s)
		return;
	if (s == e) {
		if (v > tree[n].first) {
			tree[n].first = v;
			tree[n].second = idx;
		}
		return;
	}
	int mid = (s + e) / 2;
	update(t, v, idx, n * 2, s, mid), update(t, v, idx, n * 2 + 1, mid + 1, e);
	tree[n] = max(tree[n * 2], tree[n * 2 + 1]);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	scanf("%d%d", &n, &d);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &in[i]);
		rnk.push_back(in[i]);
		rnk.push_back(in[i] - d);
		rnk.push_back(in[i] + d);
	}
	sort(rnk.begin(), rnk.end());
	rnk.erase(unique(rnk.begin(), rnk.end()), rnk.end());
	build();
	memset(prv, -1, sizeof prv);
	int maxi = 0, maxID = -1;
	for (int i = 0; i < n; i++) {
		int qs = getRnk(in[i] - d);
		int qe = getRnk(in[i] + d);
		pair<int, int> qq = query(0, qs);
		qq = max(qq, query(qe, (int) rnk.size() - 1));
		ans[i] = qq.first + 1;
		prv[i] = qq.second;
		if (ans[i] > maxi)
			maxi = ans[i], maxID = i;
		update(getRnk(in[i]), ans[i], i);
	}
	vector<int> out;
	while (maxID != -1) {
		out.push_back(maxID);
		maxID = prv[maxID];
	}
	reverse(out.begin(), out.end());
	printf("%d\n", out.size());
	for (int i = 0; i < (int) out.size(); i++) {
		if (i)
			printf(" ");
		printf("%d", ++out[i]);
	}
	printf("\n");
	return 0;
}
