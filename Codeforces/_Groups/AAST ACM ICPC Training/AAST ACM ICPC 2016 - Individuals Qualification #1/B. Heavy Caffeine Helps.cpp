/*
 * B. Heavy Caffeine Helps.cpp
 *
 *  Created on: Aug 29, 2016
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

	int T;
	cin >> T;
	while (T--) {
		int xx, x, y;
		cin >> xx >> x >> y;
		cout << (xx - x + y - 1) / y << endl;
	}
	return 0;
}
