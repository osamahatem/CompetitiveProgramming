/*
 * 175C. Geometry Horse.cpp
 *
 *  Created on: Apr 24, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

struct fig {
	int k, c;

	const bool operator<(const fig &a) const {
		return c < a.c;
	}
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, t;
	long long p[105];
	fig all[105];
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> all[i].k >> all[i].c;
	sort(all, all + n);
	cin >> t;
	for (int i = 0; i < t; i++)
		cin >> p[i];
	long long cur = 0, maxi = 0;
	int f = 1, idx = 0;
	while (idx < n) {
		int cnt;
		if (f == t + 1)
			cnt = all[idx].k;
		else
			cnt = min((long long) all[idx].k, p[f - 1] - cur);
		maxi += (long long) f * cnt * all[idx].c;
		cur += cnt;
		all[idx].k -= cnt;
		if (!all[idx].k)
			idx++;
		if (f <= t && cur == p[f - 1])
			f++;
	}
	cout << maxi << endl;
	return 0;
}
