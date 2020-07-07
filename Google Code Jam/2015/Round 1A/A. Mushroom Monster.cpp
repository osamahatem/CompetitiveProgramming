/*
 * A. Mushroom Monster.cpp
 *
 *  Created on: Apr 18, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif

	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		int n, m[1005];
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> m[i];
		cout << "Case #" << t << ": ";
		int ans = 0;
		for (int i = 1; i < n; i++)
			ans += max(m[i - 1] - m[i], 0);
		cout << ans << " ";
		ans = 0;
		int sp = 0;
		for (int i = 1; i < n; i++)
			sp = max(sp, m[i - 1] - m[i]);
		for (int i = 1; i < n; i++)
			ans += min(m[i - 1], max(sp, m[i - 1] - m[i]));
		cout << ans << endl;
	}
	return 0;
}
