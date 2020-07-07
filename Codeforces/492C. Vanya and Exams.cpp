/*
 * 492C. Vanya and Exams.cpp
 *
 *  Created on: Dec 1, 2014
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, r, avg, a, b;
	cin >> n >> r >> avg;
	long long tar = (long long) avg * n;
	vector<pair<int, int> > all;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		all.push_back(make_pair(b, r - a));
		tar -= a;
	}
	sort(all.begin(), all.end());
	int idx = 0;
	long long ans = 0;
	while (tar > 0) {
		long long temp = min(tar, (long long) all[idx].second);
		tar -= temp;
		temp *= all[idx].first;
		ans += temp;
		idx++;
	}
	cout << ans << endl;
	return 0;
}
