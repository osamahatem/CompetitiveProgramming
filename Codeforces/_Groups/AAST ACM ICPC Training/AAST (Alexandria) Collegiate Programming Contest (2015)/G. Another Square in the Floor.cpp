/*
 * G. Another Square in the Floor.cpp
 *
 *  Created on: Oct 21, 2015
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

	freopen("square.in", "r", stdin);
	int T, x, y;
	cin >> T;
	while (T--) {
		cin >> x >> y;
		x = max(x, y);
		cout << x * x << endl;
	}
	return 0;
}
