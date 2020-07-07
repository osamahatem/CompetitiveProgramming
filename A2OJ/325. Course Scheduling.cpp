/*
 * 325. Course Scheduling.cpp
 *
 *  Created on: Nov 12, 2014
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

	int t, tc = 0;
	cin >> t;
	while (t--) {
		int n, m, x, ans = 0;
		cin >> n >> m;
		while (m--) {
			cin >> x;
			if (x * 2 >= n)
				ans++;
		}
		cout << "Case " << ++tc << ": " << ans << endl;
	}
	return 0;
}
