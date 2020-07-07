/*
 * F. Game of Cubes.cpp
 *
 *  Created on: Sep 15, 2015
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

	freopen("cubes.in", "r", stdin);
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		if (n < 3)
			cout << n << endl;
		else {
			long long ans = 0;
			for (int i = max(1, n - 10); i <= n; i++)
				for (int j = i + 1; j <= n; j++)
					for (int k = j + 1; k <= n; k++) {
						long long lcm = 1ll * i * j / __gcd(i, j);
						lcm = (lcm * k) / __gcd(lcm, 1ll * k);
						ans = max(ans, lcm);
					}
			cout << ans << endl;
		}
	}
	return 0;
}
