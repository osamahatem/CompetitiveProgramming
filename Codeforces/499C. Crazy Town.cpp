/*
 * 499C. Crazy Town.cpp
 *
 *  Created on: Dec 25, 2014
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

	int x1, y1, x2, y2, n, a, b, c, ans = 0;
	cin >> x1 >> y1 >> x2 >> y2 >> n;
	while (n--) {
		cin >> a >> b >> c;
		long long s1 = (long long) a * x1 + (long long) b * y1 + c;
		long long s2 = (long long) a * x2 + (long long) b * y2 + c;
		if ((s1 < 0 && s2 > 0) || (s1 > 0 && s2 < 0))
			ans++;
	}
	cout << ans << endl;
	return 0;
}
