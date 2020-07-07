/*
 * 557A. Ilya and Diplomas.cpp
 *
 *  Created on: Jun 30, 2015
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

	int n, a1, b1, a2, b2, a3, b3;
	cin >> n >> a1 >> b1 >> a2 >> b2 >> a3 >> b3;
	int ans[3] = { a1, a2, a3 };
	n -= a1 + a2 + a3;
	while (n && ans[0] < b1)
		ans[0]++, n--;
	while (n && ans[1] < b2)
		ans[1]++, n--;
	while (n && ans[2] < b3)
		ans[2]++, n--;
	cout << ans[0] << " " << ans[1] << " " << ans[2] << endl;
	return 0;
}
