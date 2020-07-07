/*
 * sterilizing.cpp
 *
 *  Created on: Jun 14, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;

int arr[MAXN];
long long tree[4 * MAXN];

void build(int n, int s, int e) {
	if (s == e) {
		tree[n] = arr[s];
		return;
	}
	int mid = (s + e) / 2;
	build(n * 2, s, mid);
	build(n * 2 + 1, mid + 1, e);
	tree[n] = tree[n * 2] + tree[n * 2 + 1];
}

void update(int n, int s, int e, int q) {
	if (q < s || q > e)
		return;
	if (s == e) {
		tree[n] = arr[s];
		return;
	}
	int mid = (s + e) / 2;
	update(n * 2, s, mid, q);
	update(n * 2 + 1, mid + 1, e, q);
	tree[n] = tree[n * 2] + tree[n * 2 + 1];
}

long long query(int n, int s, int e, int qs, int qe) {
	if (qe < s || qs > e)
		return 0;
	if (s >= qs && e <= qe)
		return tree[n];
	int mid = (s + e) / 2;
	long long ret = query(n * 2, s, mid, qs, qe);
	ret += query(n * 2 + 1, mid + 1, e, qs, qe);
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
//	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int N, Q, K, qt, a1, a2;
	map<int, int> edit;
	map<int, int>::iterator it;
	cin >> N >> Q >> K;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		edit[i] = arr[i];
	}
	build(1, 0, N - 1);
	while (Q--) {
		cin >> qt >> a1 >> a2;
		if (qt == 1) {
			a1--;
			arr[a1] = a2;
			edit[a1] = a2;
			update(1, 0, N - 1, a1);
		} else if (qt == 2 && K > 1) {
			a1--, a2--;
			it = edit.lower_bound(a1);
			vector<int> del;
			for (; it != edit.end() && it->first <= a2; it++) {
				it->second /= K;
				arr[it->first] = it->second;
				update(1, 0, N - 1, it->first);
				if (it->second == 0)
					del.push_back(it->first);
			}
			for (int i = 0; i < (int) del.size(); i++)
				edit.erase(del[i]);
		} else if (qt == 3)
			cout << query(1, 0, N - 1, a1 - 1, a2 - 1) << endl;
	}
	return 0;
}
