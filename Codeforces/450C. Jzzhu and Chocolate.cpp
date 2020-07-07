/*
 * 450C. Jzzhu and Chocolate.cpp
 *
 *  Created on: Jul 3, 2015
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
	if (k > m + n - 2) {
		cout << "-1" << endl;
		return 0;
	}
	long long ans = 0;
	if (m >= k + 1)
		ans = (long long) n * (m / (k + 1));
	if (n >= k + 1)
		ans = max(ans, (long long) (n / (k + 1)) * m);
	for (int i = 1; i * i <= n; i++) {
		int x = n / i;
		int y = k + 2 - x;
		if (y > m || x > k + 1)
			continue;
		ans = max(ans, (long long) (n / x) * (m / y));
	}
	for (int i = 1; i * i <= m; i++) {
		int x = m / i;
		int y = k + 2 - x;
		if (y > n || x > k + 1)
			continue;
		ans = max(ans, (long long) (m / x) * (n / y));
	}
	cout << ans << endl;
	return 0;
}
