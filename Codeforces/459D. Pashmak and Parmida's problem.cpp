/*
 * 459D. Pashmak and Parmida's problem.cpp
 *
 *  Created on: Aug 15, 2014
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e6 + 5;

int n, arr[MAXN], cnt[MAXN], f[MAXN], sum[4 * MAXN];
map<int, int> rnk;

void update(int n, int s, int e, int &t) {
	if (s == t && e == t) {
		sum[n] = 1;
		return;
	}
	if (e < t || s > t)
		return;
	int mid = (e + s) / 2;
	update(n * 2, s, mid, t);
	update(n * 2 + 1, mid + 1, e, t);
	sum[n] = sum[n * 2] + sum[n * 2 + 1];
}

int query(int n, int s, int e, int &qs, int &qe) {
	if (s >= qs && e <= qe)
		return sum[n];
	if (e < qs || s > qe)
		return 0;
	int mid = (s + e) / 2, ret = 0;
	ret += query(n * 2, s, mid, qs, qe);
	ret += query(n * 2 + 1, mid + 1, e, qs, qe);
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	scanf("%d", &n);
	int r = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		if (!rnk.count(arr[i]))
			rnk[arr[i]] = ++r;
	}
	vector<pair<int, int> > U, Q;
	for (int i = n - 1; i >= 0; i--) {
		arr[i] = rnk[arr[i]];
		U.push_back(make_pair(1 + cnt[arr[i]], i));
		cnt[arr[i]]++;
	}
	sort(U.begin(), U.end());
	memset(cnt, 0, sizeof cnt);
	for (int i = 0; i < n; i++) {
		Q.push_back(make_pair(1 + cnt[arr[i]], i));
		cnt[arr[i]]++;
	}
	n--;
	sort(Q.begin(), Q.end());
	int idx = 0;
	long long ans = 0;
	for (int i = 0; i < (int) Q.size(); i++) {
		while (idx < (int) U.size() && U[idx].first < Q[i].first) {
			update(1, 0, n, U[idx].second);
			idx++;
		}
		int qs = Q[i].second + 1;
		ans += query(1, 0, n, qs, n);
	}
	printf("%I64d\n", ans);
	return 0;
}
