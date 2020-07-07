/*
 * COCI.cpp
 *
 *  Created on: Nov 29, 2014
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

struct node {
	int a, b, idx, more, less;

	static const bool cmp1(const node &x, const node &y) {
		if (x.a != y.a)
			return x.a > y.a;
		return x.b > y.b;
	}

	static const bool cmp2(const node &x, const node &y) {
		return x.idx < y.idx;
	}
};

int tree[2800];

void build() {
	memset(tree, 0, sizeof tree);
}

int query(int n, int s, int e, int qs, int qe) {
	if (s > qe || e < qs || qs > qe)
		return 0;
	if (s >= qs && e <= qe)
		return tree[n];
	int m = (s + e) / 2;
	int ret = query(n * 2, s, m, qs, qe);
	ret += query(n * 2 + 1, m + 1, e, qs, qe);
	return ret;
}

void update(int n, int s, int e, int q) {
	if (s > q || e < q)
		return;
	if (s == e) {
		tree[n]++;
		return;
	}
	int m = (s + e) / 2;
	update(n * 2, s, m, q);
	update(n * 2 + 1, m + 1, e, q);
	tree[n] = tree[n * 2] + tree[n * 2 + 1];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, a, b;
	cin >> n;
	vector<node> all;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		all.push_back(node { a, b, i, 0, 0 });
	}
	sort(all.begin(), all.end(), node::cmp1);
	build();
	int last = all[0].a, idx = 0;
	for (int i = 0; i < n; i++) {
		if (all[i].a != last) {
			for (int j = idx; j < i; j++)
				update(1, 0, 650, all[j].b);
			last = all[i].a, idx = i;
		}
		all[i].less = query(1, 0, 650, all[i].b + 1, 650);
	}
	build();
	last = all[n - 1].a, idx = n - 1;
	for (int i = n - 1; i >= 0; i--) {
		if (all[i].a != last) {
			for (int j = idx; j > i; j--)
				update(1, 0, 650, all[j].b);
			last = all[i].a, idx = i;
		}
		all[i].more = query(1, 0, 650, 0, all[i].b - 1);
	}
	sort(all.begin(), all.end(), node::cmp2);
	for (int i = 0; i < n; i++)
		cout << 1 + all[i].less << " " << n - all[i].more << endl;
	return 0;
}
