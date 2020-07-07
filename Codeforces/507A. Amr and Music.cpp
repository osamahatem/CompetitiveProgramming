/*
 * 507A. Amr and Music.cpp
 *
 *  Created on: Jan 24, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
//	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, k, a;
	vector<pair<int, int> > all;
	vector<int> ans;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a;
		all.push_back(make_pair(a, i + 1));
	}
	sort(all.begin(), all.end());
	for (int i = 0; i < (int) all.size(); i++) {
		if (k < all[i].first)
			break;
		ans.push_back(all[i].second);
		k -= all[i].first;
	}
	cout << ans.size() << endl;
	for (int i = 0; i < (int) ans.size(); i++) {
		if (i)
			cout << " ";
		cout << ans[i];
	}
	cout << endl;
	return 0;
}
