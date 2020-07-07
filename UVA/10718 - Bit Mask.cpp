/*
 * 10718 - Bit Mask.cpp
 *
 *  Created on: Oct 9, 2014
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

	long long n, l, h;
	while (cin >> n >> l >> h) {
		long long m = 0;
		bool fh = true, fl = true;
		for (int i = 31; i >= 0; i--) {
			bool bl = (bool) (l & (1ll << i));
			bool bh = (bool) (h & (1ll << i));
			bool bn = (bool) (n & (1ll << i));
			if (fl && bl)
				m |= 1ll << i;
			else if ((bh || !fh) && !bn) {
				m |= 1ll << i;
				if (!bl)
					fl = false;
			} else if (bn && bh && fh && (!bl || !fl))
				fh = false;
		}
		cout << m << "\n";
	}
	return 0;
}
