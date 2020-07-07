/*
 * 55C. Pie or die.cpp
 *
 *  Created on: Aug 7, 2015
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

	int n, m, k, x, y;
	cin >> n >> m >> k;
	while (k--) {
		cin >> x >> y;
		if (x <= 5 || y <= 5 || x > n - 5 || y > m - 5) {
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	return 0;
}
