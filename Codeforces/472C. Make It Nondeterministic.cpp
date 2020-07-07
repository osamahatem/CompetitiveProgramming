/*
 * 472C. Make It Nondeterministic.cpp
 *
 *  Created on: Sep 28, 2014
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

	int n;
	cin >> n;
	vector<pair<string, string> > all(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> all[i].first >> all[i].second;
		if (all[i].first > all[i].second)
			swap(all[i].first, all[i].second);
	}
	bool flag = 1;
	int x;
	cin >> x;
	string last = all[x].first;
	for (int i = 1; i < n; i++) {
		cin >> x;
		if (all[x].first > last)
			last = all[x].first;
		else if (all[x].second > last)
			last = all[x].second;
		else {
			flag = 0;
			break;
		}
	}
	cout << (flag ? "YES\n" : "NO\n");
	return 0;
}
