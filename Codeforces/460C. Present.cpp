/*
 * 460C. Present.cpp
 *
 *  Created on: Aug 20, 2014
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;

pair<int, int> tree[4 * MAXN];
int lazy[4 * MAXN], arr[MAXN];

void build(int n, int s, int e) {
	if (s == e) {
		tree[n].first = arr[s];
		tree[n].second = s;
		return;
	}
	int mid = (s + e) / 2;
	build(n * 2, s, mid);
	build(n * 2 + 1, mid + 1, e);
	tree[n] = min(tree[n * 2], tree[n * 2 + 1]);
}

void relax(int n, int val) {
	tree[n].first += val;
	lazy[n] += val;
}

void update(int n, int s, int e, int &us, int &ue, int fromUp) {
	relax(n, fromUp);
	if (s > ue || e < us)
		return;
	if (s >= us && e <= ue) {
		relax(n, 1);
		return;
	}
	int mid = (s + e) / 2;
	update(n * 2, s, mid, us, ue, lazy[n]);
	update(n * 2 + 1, mid + 1, e, us, ue, lazy[n]);
	lazy[n] = 0;
	tree[n] = min(tree[n * 2], tree[n * 2 + 1]);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, m, w;
	cin >> n >> m >> w;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	build(1, 0, n - 1);
	for (int i = 0; i < m; i++) {
		int us = min(tree[1].second, n - w);
		int ue = us + w - 1;
		update(1, 0, n - 1, us, ue, 0);
	}
	cout << tree[1].first << "\n";
	return 0;
}
