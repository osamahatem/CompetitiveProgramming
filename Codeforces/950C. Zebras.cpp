/*
 * 950C. Zebras.cpp
 *
 *  Created on: Apr 9, 2018
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

string s;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> s;

	deque<int> before, after;
	for (int i = 0; s[i]; i++)
		if (s[i] == '0')
			after.push_back(i);

	set<pair<int, int>> one_zero;
	for (int i = 0; s[i]; i++) {
		while (after.size() && after.front() <= i) {
			before.push_back(after.front());
			after.pop_front();
		}
		if (s[i] == '1') {
			if (after.empty()) {
				cout << "-1" << endl;
				return 0;
			}
			one_zero.insert(make_pair(i, after.front()));
			after.pop_front();
		}
	}

	vector<vector<int>> ans;
	for (int i = 0; i < (int) before.size(); i++) {
		vector<int> temp;
		temp.push_back(before[i]);
		auto nxt = one_zero.lower_bound(make_pair(before[i], before[i]));
		while (nxt != one_zero.end()) {
			temp.push_back(nxt->first);
			temp.push_back(nxt->second);
			int x = nxt->second;
			one_zero.erase(nxt);
			nxt = one_zero.lower_bound(make_pair(x, x));
		}
		ans.push_back(temp);
	}

	if (one_zero.size()) {
		cout << "-1" << endl;
		return 0;
	}

	cout << ans.size() << endl;
	for (auto v : ans) {
		cout << v.size();
		for (auto x : v)
			cout << " " << x + 1;
		cout << endl;
	}
	return 0;
}
