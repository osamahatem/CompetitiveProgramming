/*
 * 950A. Left-handers, Right-handers and Ambidexters.cpp
 *
 *  Created on: Apr 9, 2018
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

	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int l, r, a;
	cin >> l >> r >> a;

	if (l > r)
		swap(l, r);

	int temp = min(a, r - l);
	a -= temp, l += temp;

	int ans = 0;
	if (l == r)
		ans = l + r + a / 2 * 2;
	else
		ans = l + l;
	cout << ans << endl;
	return 0;
}
