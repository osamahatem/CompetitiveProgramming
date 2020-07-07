/*
 * 492D. Vanya and Computer Game.cpp
 *
 *  Created on: Dec 1, 2014
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
	long long x, y, a;
	cin >> n >> x >> y;
	long long lcm = x * y / __gcd(x, y);
	while (n--) {
		cin >> a;
		long long h = a * x, l = 0, m;
		while (l <= h) {
			m = (h + l) / 2;
			long long hits = m / x + m / y;
//			cout << l << " " << h << " " << m << " " << hits << endl;
			if ((hits == a && (m % x == 0 || m % y == 0))
					|| (hits == a + 1 && m % lcm == 0))
				break;
			if (hits < a)
				l = m + 1;
			else
				h = m - 1;
		}
//		cout << m << endl;
		if (m % x == 0 && m % y == 0)
			cout << "Both\n";
		else if (m % x == 0)
			cout << "Vova\n";
		else
			cout << "Vanya\n";
	}
	return 0;
}
