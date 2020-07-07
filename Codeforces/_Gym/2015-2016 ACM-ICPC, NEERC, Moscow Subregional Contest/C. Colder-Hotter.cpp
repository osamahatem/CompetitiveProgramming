/*
 * C. Colder-Hotter.cpp
 *
 *  Created on: Sep 27, 2016
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

	int x, y = 0, in;
	int s = 0, e = 1e9;
	while (s <= e) {
		int sz = (e - s) / 3;
		int m1 = s + sz, m2 = e - sz;
		cout << m1 << " " << y << endl << endl;
		cin >> in;
		cout << m2 << " " << y << endl << endl;
		cin >> in;
		if (in == 1)
			x = m2, s = m1 + 1;
		else
			x = m1, e = m2 - 1;
	}
	s = 0, e = 1e9;
	while (s <= e) {
		int sz = (e - s) / 3;
		int m1 = s + sz, m2 = e - sz;
		cout << x << " " << m1 << endl << endl;
		cin >> in;
		cout << x << " " << m2 << endl << endl;
		cin >> in;
		if (in == 1)
			y = m2, s = m1 + 1;
		else
			y = m1, e = m2 - 1;
	}
	cout << "A " << x << " " << y << endl << endl;
	return 0;
}
