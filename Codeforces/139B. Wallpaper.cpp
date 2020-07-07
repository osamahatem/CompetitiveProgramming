/*
 * 139B. Wallpaper.cpp
 *
 *  Created on: Aug 5, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int per[505], hei[505], mini[505];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, m, w, l, h;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> l >> w >> h;
		per[i] = 2 * (l + w), hei[i] = h;
		mini[i] = 1 << 30;
	}
	cin >> m;
	while (m--) {
		cin >> l >> w >> h;
		for (int i = 0; i < n; i++)
			if (l >= hei[i]) {
				int ww = w * (l / hei[i]);
				mini[i] = min(mini[i], (per[i] + ww - 1) / ww * h);
			}
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
		ans += mini[i];
	cout << ans << endl;
	return 0;
}
