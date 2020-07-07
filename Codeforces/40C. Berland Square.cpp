/*
 * 40C. Berland Square.cpp
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

	int c1, c2, r1, r2;
	cin >> r1 >> c1 >> r2 >> c2;
	if (c2 < c1)
		swap(r1, r2), swap(c1, c2);
	long long ans = r2 + 1;
	if (c1 + r1 > c2)
		ans -= min(c1 + r1, c2 + r2) - c2;
	for (int i = 0; i < r1; i++) {
		ans++;
		int left = c1 - i, right = c1 + i;
		if (c2 > right) {
			ans += r2 >= c2 - right;
			ans += 2 * max(r2 - c2 + right, 0);
			ans -= 2 * max(r2 - c2 + left, 0);
		} else {
			ans += r2 > right - c2;
			ans += 2 * max(r2 - right + c2 - 1, 0);
			ans -= 2 * max(r2 - c2 + left, 0);
		}
	}
	cout << ans << endl;
	return 0;
}
