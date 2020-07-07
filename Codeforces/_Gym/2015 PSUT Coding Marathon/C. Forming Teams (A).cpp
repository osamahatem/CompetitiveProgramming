/*
 * C. Forming Teams (A).cpp
 *
 *  Created on: Sep 3, 2015
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

	int n, m, x, y, z;
	cin >> m >> n >> x >> y >> z;
	if (n > 0) {
		int temp = min(n, x);
		x -= temp, n -= temp;
	}
	if (n > 0) {
		int temp = min(n, y);
		y -= temp, n -= temp;
	}
	if (n > 0) {
		int temp = min(n, z);
		z -= temp, n -= temp;
	}
	m -= x + 2 * y + 3 * z;
	cout << (m > 0 || n > 0 ? "No" : "Yes") << endl;
	return 0;
}
