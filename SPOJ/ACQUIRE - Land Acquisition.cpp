/*
 * ACQUIRE - Land Acquisition.cpp
 *
 *  Created on: Aug 20, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 5e4 + 5;

struct node {
	int s, m;
	long long c;

	const bool operator <(const node &other) const {
		return s < other.s;
	}
};

int n, sz;
pair<int, int> lands[MAXN], arr[MAXN];
long long dp[MAXN];

long long inter(int m1, long long c1, int m2, long long c2) {
	long long a = c2 - c1, b = m1 - m2;
	long long ret = (abs(a) + abs(b) - 1) / abs(b);
	if (a / abs(a) != b / abs(b))
		ret *= -1;
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d%d", &lands[i].first, &lands[i].second);
	sort(lands, lands + n, greater<pair<int, int>>());
	arr[sz++] = lands[0];
	for (int i = 1; i < n; i++) {
		while (i < n && lands[i].second <= arr[sz - 1].second)
			i++;
		if (i < n)
			arr[sz++] = lands[i];
	}
	deque<node> Q;
	for (int i = 0; i < sz; i++) {
		long long c = i ? dp[i - 1] : 0;
		int m = arr[i].first;
		while (Q.size() && inter(m, c, Q.back().m, Q.back().c) <= Q.back().s)
			Q.pop_back();
		int interr;
		if (Q.size())
			interr = inter(m, c, Q.back().m, Q.back().c);
		else
			interr = 0;
		Q.push_back(node { interr, m, c });
		int idx = upper_bound(Q.begin(), Q.end(), node { arr[i].second, 0, 0 })
				- Q.begin() - 1;
		dp[i] = 1ll * Q[idx].m * arr[i].second + Q[idx].c;
	}
	cout << dp[sz - 1] << endl;
	return 0;
}
