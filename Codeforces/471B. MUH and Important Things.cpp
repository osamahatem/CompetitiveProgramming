/*
 * 471B. MUH and Important Things.cpp
 *
 *  Created on: Jun 9, 2015
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

	int n, x;
	cin >> n;
	vector<pair<int, int> > all;
	for (int i = 0; i < n; i++) {
		cin >> x;
		all.push_back(make_pair(x, i + 1));
	}
	sort(all.begin(), all.end());
	set<pair<int, int> > swaps;
	vector<pair<int, int> > ans[3];
	ans[0] = all;
	for (int i = 1; i < 3; i++) {
		bool flag = 0;
		for (int j = 0; j + 1 < n; j++)
			if (all[j].first == all[j + 1].first
					&& !swaps.count(
							make_pair(all[j].second, all[j + 1].second))) {
				swaps.insert(make_pair(all[j].second, all[j + 1].second));
				swaps.insert(make_pair(all[j + 1].second, all[j].second));
				swap(all[j], all[j + 1]);
				flag = 1;
				break;
			}
		if (!flag) {
			cout << "NO" << endl;
			return 0;
		}
		ans[i] = all;
	}
	cout << "YES" << endl;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < n; j++) {
			if (j)
				cout << " ";
			cout << ans[i][j].second;
		}
		cout << endl;
	}
	return 0;
}
