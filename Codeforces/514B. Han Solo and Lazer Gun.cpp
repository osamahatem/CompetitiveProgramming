/*
 * 514B. Han Solo and Lazer Gun.cpp
 *
 *  Created on: Jun 9, 2015
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

	int n, x0, y0, x, y;
	cin >> n >> x0 >> y0;
	set<pair<int, int> > slopes;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		int dx = x - x0, dy = y - y0;
		if (dy == 0)
			slopes.insert(make_pair(0, 1));
		else if (dx == 0)
			slopes.insert(make_pair(1, 0));
		else {
			int g = __gcd(abs(dx), abs(dy));
			dx /= g, dy /= g;
			if (dx > 0 && dy < 0)
				dx *= -1, dy *= -1;
			if (dx < 0 && dy < 0)
				dx *= -1, dy *= -1;
			slopes.insert(make_pair(dx, dy));
		}
	}
	int ans = slopes.size();
	cout << ans << endl;
	return 0;
}
