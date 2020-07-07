/*
 * 552A. Vanya and Table.cpp
 *
 *  Created on: Jun 18, 2015
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

	int n, x1, x2, y1, y2, ans = 0;
	cin >> n;
	while (n--) {
		cin >> x1 >> y1 >> x2 >> y2;
		ans += (x2 - x1 + 1) * (y2 - y1 + 1);
	}
	cout << ans << endl;
	return 0;
}
