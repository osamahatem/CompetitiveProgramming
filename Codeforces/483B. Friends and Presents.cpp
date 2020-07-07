/*
 * 483B. Friends and Presents.cpp
 *
 *  Created on: Oct 24, 2014
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int c1, c2, x, y;

bool check(int m) {
	int all = m - m / x - m / y + m / (x * y);
	int oc1 = m / y - m / (x * y);
	int oc2 = m / x - m / (x * y);
	return (c1 + c2 - min(c1, oc1) - min(c2, oc2) <= all);
}

int main() {
#ifndef ONLINE_JUDGE
//	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin >> c1 >> c2 >> x >> y;
	long long s = c1 + c2, e = 2 * s, m, ans;
	while (s <= e) {
		m = (s + e) / 2;
		if (check(m)) {
			ans = m;
			e = m - 1;
		} else
			s = m + 1;
	}
	cout << ans << endl;
	return 0;
}
