/*
 * 567A. Lineland Mail.cpp
 *
 *  Created on: Aug 6, 2015
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
	vector<int> all;
	cin >> n;
	all.resize(n);
	for (int i = 0; i < n; i++)
		cin >> all[i];
	cout << all[1] - all[0] << " " << all[n - 1] - all[0] << endl;
	for (int i = 1; i + 1 < n; i++) {
		cout << min(all[i + 1] - all[i], all[i] - all[i - 1]) << " ";
		cout << max(all[n - 1] - all[i], all[i] - all[0]) << endl;
	}
	cout << all[n - 1] - all[n - 2] << " " << all[n - 1] - all[0] << endl;
	return 0;
}
