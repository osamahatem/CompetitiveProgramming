/*
 * 545A. Toy Cars.cpp
 *
 *  Created on: May 19, 2015
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
	set<int> ans;
	cin >> n;
	for (int i = 0; i < n; i++)
		ans.insert(i);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> x;
			if (x == 1)
				ans.erase(i);
			if (x == 2)
				ans.erase(j);
			if (x == 3)
				ans.erase(i), ans.erase(j);
		}
	}
	cout << ans.size() << endl;
	for (set<int>::iterator it = ans.begin(); it != ans.end(); it++) {
		if (it != ans.begin())
			cout << " ";
		cout << (*it) + 1;
	}
	if (ans.size())
		cout << endl;
	return 0;
}
