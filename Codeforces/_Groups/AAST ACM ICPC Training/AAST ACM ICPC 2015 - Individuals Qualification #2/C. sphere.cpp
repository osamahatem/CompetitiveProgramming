/*
 * C. sphere.cpp
 *
 *  Created on: Sep 7, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const double EPS = 1e-9;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	freopen("sphere.in", "r", stdin);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		int r, p, x, y, z, ans = 0;
		cin >> r >> p;
		while (p--) {
			cin >> x >> y >> z;
			double dist = sqrt(x * x + y * y + z * z);
			ans += dist - r < EPS;
		}
		cout << "Case " << t << ": " << ans << endl;
	}
	return 0;
}
