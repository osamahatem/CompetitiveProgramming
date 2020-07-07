/*
 * J. Judging Moose.cpp
 *
 *  Created on: Oct 24, 2017
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

	int l, r;
	cin >> l >> r;
	cout << (l + r == 0 ? "Not a moose" : (l == r ? "Even" : "Odd"));
	if (l || r)
		cout << " " << max(l, r) * 2 << endl;
	return 0;
}
