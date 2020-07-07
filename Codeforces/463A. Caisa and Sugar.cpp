/*
 * 463A. Caisa and Sugar.cpp
 *
 *  Created on: Jul 11, 2016
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

	int n, s, x, y, ans = -1;
	cin >> n >> s;
	s *= 100;
	while (n--) {
		cin >> x >> y;
		x = x * 100 + y;
		if (x <= s)
			ans = max(ans, (s - x) % 100);
	}
	cout << ans << endl;
	return 0;
}
