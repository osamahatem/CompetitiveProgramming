/*
 * 401B. Sereja and Contests.cpp
 *
 *  Created on: Jul 18, 2015
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

	int x, k, c1, c2, t;
	cin >> x >> k;
	vector<int> all;
	all.push_back(x);
	while (k--) {
		cin >> t >> c2;
		all.push_back(c2);
		if (t == 1) {
			cin >> c1;
			all.push_back(c1);
		}
	}
	sort(all.begin(), all.end());
	int maxi = x - all.size();
	int mini = all[0] / 2;
	for (int i = 1; i < (int) all.size(); i++)
		mini += (all[i] - all[i - 1]) / 2;
	cout << mini << " " << maxi << endl;
	return 0;
}
