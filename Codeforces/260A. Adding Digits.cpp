/*
 * 260A. Adding Digits.cpp
 *
 *  Created on: May 8, 2016
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

	int a, b, n;
	cin >> a >> b >> n;
	int mod = a % b;
	string ans = "";
	while (a) {
		ans += '0' + a % 10;
		a /= 10;
	}
	reverse(ans.begin(), ans.end());
	for (int i = 0; i < n; i++) {
		mod = mod * 10 % b;
		int d;
		for (d = 0; d < 10; d++)
			if ((mod + d) % b == 0)
				break;
		if (d == 10) {
			printf("-1\n");
			return 0;
		}
		ans += '0' + d;
		mod = (mod + d) % b;
	}
	printf("%s\n", ans.c_str());
	return 0;
}
