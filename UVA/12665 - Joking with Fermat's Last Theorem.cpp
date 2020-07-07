/*
 * 12665 - Joking with Fermat's Last Theorem.cpp
 *
 *  Created on: Aug 31, 2014
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

	int t = 0;
	long long x, y;
	while (cin >> x >> y) {
		int ans = 0;
		cout << "Case " << ++t << ": ";
		for (long long a = x; a <= y; a++) {
			long long A = a * a * a;
			if ((A * 2) / 10 > y)
				break;
			for (long long b = a; (b * b * b + A) / 10 <= y; b++) {
				long long C = b * b * b + A;
				if (C % 10 == 3)
					ans += 2;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
