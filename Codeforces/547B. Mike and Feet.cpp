/*
 * 547B. Mike and Feet.cpp
 *
 *  Created on: May 26, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 2e5 + 5;
const int INF = 1 << 30;

int arr[MAXN], ans[MAXN], N;
pair<int, int> tree[4 * MAXN];

void build(int n, int s, int e) {
	if (s == e) {
		tree[n] = make_pair(arr[s], s);
		return;
	}
	int mid = (s + e) / 2;
	build(n * 2, s, mid);
	build(n * 2 + 1, mid + 1, e);
	tree[n] = min(tree[n * 2], tree[n * 2 + 1]);
}

pair<int, int> query(int n, int s, int e, int qs, int qe) {
	if (e < qs || s > qe)
		return make_pair(INF, 0);
	if (s >= qs && e <= qe)
		return tree[n];
	int mid = (s + e) / 2;
	pair<int, int> ret = query(n * 2, s, mid, qs, qe);
	ret = min(ret, query(n * 2 + 1, mid + 1, e, qs, qe));
	return ret;
}

void solve(int s, int e) {
	if (s < 0 || s >= N || e < 0 || e >= N || e < s)
		return;
	if (s == e) {
		ans[0] = max(ans[0], arr[s]);
		return;
	}
	pair<int, int> sp = query(1, 0, N - 1, s, e);
	ans[e - s] = max(ans[e - s], sp.first);
	solve(s, sp.second - 1);
	solve(sp.second + 1, e);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	build(1, 0, N - 1);
	solve(0, N - 1);
	for (int i = N - 1; i >= 0; i--)
		ans[i] = max(ans[i], ans[i + 1]);
	for (int i = 0; i < N; i++) {
		if (i)
			cout << " ";
		cout << ans[i];
	}
	cout << endl;
	return 0;
}
