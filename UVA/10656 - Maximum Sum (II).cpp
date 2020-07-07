/*
 * 10656 - Maximum Sum (II).cpp
 *
 *  Created on: Sep 30, 2014
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
	while (cin >> n, n) {
		bool flag = 0;
		while (n--) {
			cin >> x;
			if (x) {
				if (flag)
					cout << " ";
				cout << x;
				flag = 1;
			}
		}
		if (!flag)
			cout << '0';
		cout << "\n";
	}
	return 0;
}
