/*
 * 479B. Towers.cpp
 *
 *  Created on: Jun 11, 2016
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

	int n, k;
	set<pair<int, int>> all;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		all.insert(make_pair(x, i));
	}
	vector<pair<int, int>> ops;
	for (int i = 0; i < k; i++) {
		pair<int, int> mini = *all.begin();
		pair<int, int> maxi = *all.rbegin();
		if (maxi.first - mini.first < 2)
			break;
		all.erase(all.begin());
		all.erase(--all.end());
		mini.first++, maxi.first--;
		ops.push_back(make_pair(maxi.second, mini.second));
		all.insert(mini);
		all.insert(maxi);
	}
	pair<int, int> mini = *all.begin();
	pair<int, int> maxi = *all.rbegin();
	cout << maxi.first - mini.first << " " << ops.size() << endl;
	for (int i = 0; i < (int) ops.size(); i++)
		cout << ops[i].first << " " << ops[i].second << endl;
	return 0;
}
