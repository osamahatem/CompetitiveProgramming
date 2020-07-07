/*
 * 189B. Counting Rhombi.cpp
 *
 *  Created on: May 18, 2015
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

	int w, h;
	long long ans = 0;
	cin >> w >> h;
	for (int ww = 2; ww <= w; ww += 2)
		for (int hh = 2; hh <= h; hh += 2)
			ans += (h - hh + 1) * (w - ww + 1);
	cout << ans << endl;
	return 0;
}
