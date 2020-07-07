/*
 * 12650 - Dangerous Dive.cpp
 *
 *  Created on: Aug 16, 2014
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

	int n, r;
	while (cin >> n >> r) {
		int x;
		set<int> all;
		for (int i = 0; i < r; i++) {
			cin >> x;
			all.insert(x);
		}
		for (int i = 1; i <= n; i++)
			if (!all.count(i))
				cout << i << " ";
		if (r == n)
			cout << "*";
		cout << "\n";
	}
	return 0;
}
