/*
 * 492B. Vanya and Lanterns.cpp
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

	int n, l, x;
	vector<int> all;
	cin >> n >> l;
	for (int i = 0; i < n; i++) {
		cin >> x;
		all.push_back(x);
	}
	sort(all.begin(), all.end());
	int maxi = 0;
	for (int i = 1; i < (int) all.size(); i++)
		maxi = max(maxi, all[i] - all[i - 1]);
	double ans = maxi / 2.0;
	if (all[0] > ans)
		ans = all[0];
	if (l - all.back() > ans)
		ans = l - all.back();
	printf("%.9f\n", ans);
	return 0;
}
