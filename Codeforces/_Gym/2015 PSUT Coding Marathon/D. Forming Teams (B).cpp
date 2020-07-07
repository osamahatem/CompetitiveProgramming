/*
 * D. Forming Teams (B).cpp
 *
 *  Created on: Sep 3, 2015
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

	int n, m, k;
	cin >> n >> m >> k;
	if ((n + m + 2) / 3 > k) {
		cout << "-1" << endl;
		return 0;
	}
	int tpc = (n + 2) / 3;
	if (m <= k - tpc) {
		cout << "0" << endl;
		return 0;
	}
	int ans = m - (k - tpc);
	int temp = ans;
	if (n % 3)
		temp -= 3 - n % 3;
	if (temp > 0)
		ans += (temp + 1) / 2;
	cout << ans << endl;
	return 0;
}
