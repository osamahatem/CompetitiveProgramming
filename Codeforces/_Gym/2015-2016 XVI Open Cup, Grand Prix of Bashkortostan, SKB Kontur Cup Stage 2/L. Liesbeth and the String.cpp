/*
 * L. Liesbeth and the String.cpp
 *
 *  Created on: Jun 18, 2016
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

	long long n, ans = 0;
	cin >> n;
	while (n > 1) {
		ans += n;
		if (n & 1)
			ans++, n = (n + 1) / 2 * 3 - 1;
		else
			n >>= 1;
	}
	cout << ans << endl;
	return 0;
}
