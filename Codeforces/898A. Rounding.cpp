/*
 * 898A. Rounding.cpp
 *
 *  Created on: Dec 16, 2017
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

	int x;
	cin >> x;
	int y = x % 10;
	x -= y;
	if (y > 4)
		x += 10;
	cout << x << endl;
	return 0;
}
