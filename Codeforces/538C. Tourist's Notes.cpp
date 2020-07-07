/*
 * 538C. Tourist's Notes.cpp
 *
 *  Created on: Apr 26, 2015
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

	int n, m, d, h, ld, lh, maxi = 0;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> d >> h;
		if (!i)
			maxi = max(maxi, h + d - 1);
		else {
			if (abs(h - lh) > d - ld) {
				cout << "IMPOSSIBLE" << endl;
				return 0;
			}
			int temp = d - ld - abs(h - lh);
			maxi = max(maxi, max(h, lh) + temp / 2);
			maxi = max(maxi, h);
		}
		ld = d, lh = h;
	}
	maxi = max(maxi, lh + n - ld);
	cout << maxi << endl;
	return 0;
}
