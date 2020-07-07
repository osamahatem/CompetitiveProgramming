/*
 * 230A. Dragons.cpp
 *
 *  Created on: Jun 7, 2015
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

	int s, n;
	pair<int, int> all[1005];
	cin >> s >> n;
	for (int i = 0; i < n; i++)
		cin >> all[i].first >> all[i].second;
	sort(all, all + n);
	for (int i = 0; i < n; i++) {
		if (s <= all[i].first) {
			cout << "NO" << endl;
			return 0;
		}
		s += all[i].second;
	}
	cout << "YES" << endl;
	return 0;
}
