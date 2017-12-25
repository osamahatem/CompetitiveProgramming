/*
 * 501 - Black Box.cpp
 *
 *  Created on: Dec 25, 2017
 *      Author: Osama Hatem
 */
 
/*
Rank elements, and iterate over GET queries, incrementing elements' position as
you go, and use segment tree to get k-th element.
*/

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 3e4 + 5;

int n, m, arr[MAXN], tree[4 * MAXN];
vector<int> rnk;

int update(int t, int idx = 1, int s = 0, int e = n - 1) {
	if (s > t || e < t)
		return tree[idx];
	if (s == e)
		return ++tree[idx];
	int mid = (s + e) / 2;
	return tree[idx] = update(t, idx * 2, s, mid)
			+ update(t, idx * 2 + 1, mid + 1, e);
}

int query(int k, int idx = 1, int s = 0, int e = n - 1) {
	if (s == e)
		return rnk[s];
	int mid = (s + e) / 2;
	if (tree[idx * 2] >= k)
		return query(k, idx * 2, s, mid);
	return query(k - tree[idx * 2], idx * 2 + 1, mid + 1, e);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;
	while (T--) {
		memset(tree, 0, sizeof tree);
		rnk.clear();
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			rnk.push_back(arr[i]);
		}
		sort(rnk.begin(), rnk.end());
		rnk.erase(unique(rnk.begin(), rnk.end()), rnk.end());
		int cur = 0, x;
		for (int i = 1; i <= m; i++) {
			cin >> x;
			while (cur < x) {
				int idx = lower_bound(rnk.begin(), rnk.end(), arr[cur])
						- rnk.begin();
				update(idx);
				cur++;
			}
			cout << query(i) << endl;
		}
		if (T)
			cout << endl;
	}
	return 0;
}
