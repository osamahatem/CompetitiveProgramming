/*
 * 12646 - Zero or One.cpp
 *
 *  Created on: Aug 16, 2014
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

	int a, b, c;
	while (cin >> a >> b >> c) {
		int s = a + b + c;
		if (s == 1 || s == 2) {
			int t = ((s == 1) ? 1 : 0);
			if (a == t)
				cout << "A\n";
			else if (b == t)
				cout << "B\n";
			else
				cout << "C\n";
		} else
			cout << "*\n";
	}
	return 0;
}
