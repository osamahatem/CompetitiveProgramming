/*
 * 4D. Dowry.cpp
 *
 *  Created on: Feb 19, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int SZ = 1 << 16;

struct subset {
	long long w, v;
	int mask;

	const bool operator <(const subset &a) const {
		return w < a.w;
	}
};

subset arr[SZ];
long long tree[4 * SZ];
int maxID[4 * SZ];

void build(int n, int s, int e) {
	if (s == e) {
		tree[n] = arr[s].v;
		maxID[n] = s;
		return;
	}
	int m = (s + e) / 2;
	build(n * 2, s, m);
	build(n * 2 + 1, m + 1, e);
	if (tree[n * 2] > tree[n * 2 + 1])
		tree[n] = tree[n * 2], maxID[n] = maxID[n * 2];
	else
		tree[n] = tree[n * 2 + 1], maxID[n] = maxID[n * 2 + 1];
}

pair<long long, int> query(int n, int s, int e, int &qe) {
	if (s > qe)
		return make_pair(0, 0);
	if (e <= qe)
		return make_pair(tree[n], maxID[n]);
	int m = (s + e) / 2;
	pair<long long, int> ret = query(n * 2, s, m, qe);
	ret = max(ret, query(n * 2 + 1, m + 1, e, qe));
	return ret;
}

int main() {
//#ifndef ONLINE_JUDGE
	freopen("dowry.in", "r", stdin);
	freopen("dowry.out", "w", stdout);
//#endif

	int n, n1, n2;
	long long l, r, w[32], v[32];
	cin >> n >> l >> r;
	for (int i = 0; i < n; i++)
		cin >> w[i] >> v[i];
	n1 = (n + 1) / 2, n2 = n - n1;
	for (int i = 0; i < (1 << n2); i++) {
		arr[i].mask = i, arr[i].w = arr[i].v = 0;
		for (int j = 0; j < n2; j++) {
			if (i & (1 << j))
				arr[i].w += w[n1 + j], arr[i].v += v[n1 + j];
		}
	}
	sort(arr, arr + (1 << n2));
	build(1, 0, (1 << n2) - 1);
	long long maxi = 0;
	int m1 = 0, m2 = 0;
	for (int i = 0; i < (1 << n1); i++) {
		long long tw = 0, tv = 0;
		for (int j = 0; j < n1; j++) {
			if (i & (1 << j))
				tw += w[j], tv += v[j];
		}
		if (tw > r)
			continue;
		int idx = upper_bound(arr, arr + (1 << n2), subset { r - tw, 0, 0 })
				- arr - 1;
		pair<long long, int> qq = query(1, 0, (1 << n2) - 1, idx);
		if (qq.first + tv > maxi && arr[qq.second].w + tw >= l)
			maxi = qq.first + tv, m1 = i, m2 = arr[qq.second].mask;
	}
	int ans = 0;
	vector<int> out;
	for (int j = 0; j < n1; j++) {
		if (m1 & (1 << j))
			ans++, out.push_back(j + 1);
	}
	for (int j = 0; j < n2; j++) {
		if (m2 & (1 << j))
			ans++, out.push_back(n1 + j + 1);
	}
	cout << ans << endl;
	for (int i = 0; i < ans; i++) {
		if (i)
			cout << " ";
		cout << out[i];
	}
	cout << endl;
	return 0;
}
