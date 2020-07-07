/*
 * 488A. Giga Tower.cpp
 *
 *  Created on: Nov 21, 2014
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

bool isLucky (int x) {
	if (x < 0)
		x *= -1;
	while(x) {
		if (x % 10 == 8)
			return true;
		x /= 10;
	}
	return false;
}

int main() {
#ifndef ONLINE_JUDGE
//	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int x, ans = 1;
	cin >> x;
	while (!isLucky(x + ans))
		ans++;
	cout << ans << endl;
	return 0;
}
