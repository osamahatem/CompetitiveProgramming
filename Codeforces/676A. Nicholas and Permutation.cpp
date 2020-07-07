/*
 * 676A. Nicholas and Permutation.cpp
 *
 *  Created on: May 25, 2016
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

	int n, x, p1 = 0, pn = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		if (x == 1)
			p1 = i;
		else if (x == n)
			pn = i;
	}
	if (pn < p1)
		swap(pn, p1);
	cout << pn - p1 + max(n - 1 - pn, p1) << endl;
	return 0;
}
