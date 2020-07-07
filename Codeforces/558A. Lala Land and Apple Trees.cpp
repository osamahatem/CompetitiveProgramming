/*
 * 558A. Lala Land and Apple Trees.cpp
 *
 *  Created on: Jul 14, 2015
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

	vector<pair<int, int>> before, after;
	int n, x, a;
	cin >> n;
	while (n--) {
		cin >> x >> a;
		if (x < 0)
			before.push_back(make_pair(x, a));
		else
			after.push_back(make_pair(x, a));
	}
	sort(after.begin(), after.end());
	sort(before.begin(), before.end(), greater<pair<int, int>>());
	int ans = 0, sz = min(after.size(), before.size());
	for (int i = 0; i < sz; i++)
		ans += before[i].second + after[i].second;
	if (after.size() != before.size())
		ans += (after.size() < before.size() ? before[sz] : after[sz]).second;
	cout << ans << endl;
	return 0;
}
