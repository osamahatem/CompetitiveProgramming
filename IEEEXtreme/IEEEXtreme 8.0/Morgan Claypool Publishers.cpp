/*
 * Morgan Claypool Publishers.cpp
 *
 *  Created on: Oct 18, 2014
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

	int n, m, a, b, pos[1005];
	vector<pair<int, int> > all;
	cin >> n >> m;
	while (m--) {
		cin >> a >> b;
		all.push_back(make_pair(a, b));
	}
	for (int i = 0; i < n; i++) {
		cin >> a;
		pos[a] = i;
	}
	for (int i = 0; i < (int) all.size(); i++)
		if (pos[all[i].first] > pos[all[i].second]) {
			cout << "NO\n";
			return 0;
		}
	cout << "YES\n";
	return 0;
}
