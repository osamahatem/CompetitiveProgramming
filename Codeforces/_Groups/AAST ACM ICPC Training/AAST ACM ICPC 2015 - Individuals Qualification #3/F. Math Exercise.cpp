/*
 * F. Math Exercise.cpp
 *
 *  Created on: Sep 10, 2015
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

	freopen("math.in", "r", stdin);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		int n, ans = 0;
		cin >> n;
		for (int i = 1; i <= n; i++)
			if (n % i == 0)
				ans += i;
		cout << "Case " << t << ": " << ans << endl;
	}
	return 0;
}
