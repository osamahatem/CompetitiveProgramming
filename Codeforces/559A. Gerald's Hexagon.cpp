/*
 * 559A. Gerald's Hexagon.cpp
 *
 *  Created on: Jul 22, 2015
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

	int s[6], ans = 0;
	for (int i = 0; i < 6; i++)
		cin >> s[i];
	int cur = s[2] * 2 + 1, a = 1, b = 3, aa = 1, bb = 1;
	while (b < 5) {
		ans += cur;
		cur += aa + bb;
		s[a]--, s[b]--;
		if (!s[a])
			a--, aa = -1, cur--;
		if (!s[b])
			b++, bb = -1, cur--;
	}
	cout << ans << endl;
	return 0;
}
