/*
 * 320A. Magic Numbers.cpp
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

	int n;
	cin >> n;
	while (n) {
		if (n % 10 == 1) {
			n /= 10;
			continue;
		}
		if (n % 100 == 14) {
			n /= 100;
			continue;
		}
		if (n % 1000 == 144) {
			n /= 1000;
			continue;
		}
		break;
	}
	cout << (n ? "NO" : "YES") << endl;
	return 0;
}
