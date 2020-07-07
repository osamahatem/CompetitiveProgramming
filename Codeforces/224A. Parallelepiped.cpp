/*
 * 224A. Parallelepiped.cpp
 *
 *  Created on: Apr 17, 2015
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

	int x, y, z, ans = 0;
	cin >> x >> y >> z;
	for (int i = 1; i <= x; i++) {
		if (x % i || y % i)
			continue;
		int s1 = i, s2 = x / i, s3 = y / i;
		if (s2 * s3 != z)
			continue;
		ans = 4 * (s1 + s2 + s3);
		break;
	}
	cout << ans << endl;
	return 0;
}
