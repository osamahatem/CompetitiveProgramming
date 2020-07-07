/*
 * 378A. Playing with Dice.cpp
 *
 *  Created on: Jun 22, 2016
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

	int a, b, w = 0, d = 0, l = 0;
	cin >> a >> b;
	for (int i = 1; i <= 6; i++) {
		int da = abs(a - i), db = abs(b - i);
		if (da < db)
			w++;
		else if (da == db)
			d++;
		else
			l++;
	}
	cout << w << " " << d << " " << l << endl;
	return 0;
}
