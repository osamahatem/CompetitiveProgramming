/*
 * 374D. Inna and Sequence.cpp
 *
 *  Created on: Aug 30, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e6 + 5;

int arr[MAXN], seq[MAXN], tree[4 * MAXN];

int query(int qs, int qe, int n = 1, int s = 0, int e = MAXN) {
	if (qs > e || qe < s)
		return 0;
	if (s >= qs && e <= qe)
		return tree[n];
	int mid = (s + e) / 2;
	return query(qs, qe, n * 2, s, mid) + query(qs, qe, n * 2 + 1, mid + 1, e);
}

void update(int q, int n = 1, int s = 0, int e = MAXN) {
	if (q > e || q < s)
		return;
	if (e == s) {
		tree[n] = 1;
		return;
	}
	int mid = (s + e) / 2;
	update(q, n * 2, s, mid), update(q, n * 2 + 1, mid + 1, e);
	tree[n] = tree[n * 2] + tree[n * 2 + 1];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	memset(tree, 0, sizeof tree);
	int n, m, t, tot_len = 0, cur_len = 0;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
		scanf("%d", &arr[i]);
	while (n--) {
		scanf("%d", &t);
		if (t != -1) {
			seq[tot_len++] = t;
			cur_len++;
		} else {
			int k = upper_bound(arr, arr + m, cur_len) - arr;
			cur_len -= k;
			vector<int> ups;
			for (int i = 0; i < k; i++) {
				int s = 0, e = MAXN;
				while (s < e) {
					int mid = (s + e) / 2;
					int rem = query(0, mid);
					if (rem + arr[i] - 1 > mid)
						s = mid + 1;
					else
						e = mid;
				}
				ups.push_back(s);
			}
			for (int i = 0; i < k; i++)
				update(ups[i]);
		}
	}
	string ans;
	for (int i = 0; i < tot_len; i++)
		if (!query(i, i))
			ans += '0' + seq[i];
	cout << (ans.size() ? ans : "Poor stack!") << endl;
	return 0;
}
