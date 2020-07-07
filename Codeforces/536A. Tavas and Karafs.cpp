/*
 * 536A. Tavas and Karafs.cpp
 *
 *  Created on: Apr 14, 2015
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

	int a, b, n;
	cin >> a >> b >> n;
	while (n--) {
		int l, t, m;
		cin >> l >> t >> m;
		long long hl = (long long) b * (l - 1) + a;
		if (t < hl)
			cout << "-1" << endl;
		else {
			long long tot = (long long) m * t, s = 0, e = 1 << 20;
			while (s < e) {
				long long mid = s + (e - s + 1) / 2;
				long long sum = hl * (mid + 1);
				sum += (mid * (mid + 1) * b) / 2;
				long long hr = hl + mid * b;
				if (sum <= tot && hr <= t)
					s = mid;
				else
					e = mid - 1;
			}
			cout << s + l << endl;
		}
	}
	return 0;
}
