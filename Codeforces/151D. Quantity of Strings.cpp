/*
 * 151D. Quantity of Strings.cpp
 *
 *  Created on: Jun 15, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, m, k;
	cin >> n >> m >> k;
	if (k > 1 && k < n)
		cout << (k & 1 ? m * m : m) << endl;
	else {
		int lim = (k == n ? (n + 1) / 2 : n);
		int ans = 1;
		for (int i = 0; i < lim; i++)
			ans = 1ll * ans * m % MOD;
		cout << ans << endl;
	}
	return 0;
}
