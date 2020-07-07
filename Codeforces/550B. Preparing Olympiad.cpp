/*
 * 550B. Preparing Olympiad.cpp
 *
 *  Created on: Jun 4, 2015
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

	int n, l, r, x, c[15], ans = 0;
	cin >> n >> l >> r >> x;
	for (int i = 0; i < n; i++)
		cin >> c[i];
	for (int i = 0; i < (1 << n); i++) {
		int mini = 1 << 20, maxi = 0, cnt = 0, sum = 0;
		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) {
				maxi = max(maxi, c[j]);
				mini = min(mini, c[j]);
				sum += c[j];
				cnt++;
			}
		}
		if (sum >= l && sum <= r && maxi - mini >= x && cnt > 1)
			ans++;
	}
	cout << ans << endl;
	return 0;
}
