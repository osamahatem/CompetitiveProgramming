/*
 * 488C. Fight the Monster.cpp
 *
 *  Created on: Nov 21, 2014
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int getH(int hy, int ay, int dy, int hm, int am, int dm) {
	int ny = am - dy, nm = ay - dm;
	while (hm > 0) {
		hm -= nm;
		hy -= ny;
	}
	if (hy > 0)
		return 0;
	return abs(hy) + 1;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int hy, ay, dy, hm, am, dm, h, a, d, ans = 1 << 28;
	cin >> hy >> ay >> dy >> hm >> am >> dm >> h >> a >> d;
	for (int i = 0; !i || (i + ay - dm <= hm); i++) {
		if (i + ay <= dm)
			continue;
		for (int j = 0; !j || (j + dy <= am); j++) {
			int temp = a * i + d * j;
			int hh = getH(hy, i + ay, j + dy, hm, am, dm);
			temp += h * hh;
			ans = min(temp, ans);
		}
	}
	cout << ans << endl;
	return 0;
}
