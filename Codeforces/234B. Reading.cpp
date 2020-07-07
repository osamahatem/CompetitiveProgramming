/*
 * 234B. Reading.cpp
 *
 *  Created on: Jun 17, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int main() {
//#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
//#endif

	int n, k;
	cin >> n >> k;
	vector<pair<int, int>> all(n);
	for (int i = 0; i < n; i++) {
		cin >> all[i].first;
		all[i].second = i + 1;
	}
	sort(all.begin(), all.end(), greater<pair<int, int>>());
	cout << all[k - 1].first << endl;
	for (int i = 0; i < k; i++) {
		if (i)
			cout << " ";
		cout << all[i].second;
	}
	cout << endl;
	return 0;
}
