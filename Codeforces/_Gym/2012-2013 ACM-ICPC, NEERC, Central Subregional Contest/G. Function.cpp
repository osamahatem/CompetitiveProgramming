/*
 * G. Function.cpp
 *
 *  Created on: Oct 15, 2016
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

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int x = 0, y, b = 0;
	cin >> y;
	for (; (1 << b) <= y; b++)
		;
	b--;
	bool last = 0;
	for (; ~b; b--) {
		bool cur = y & (1 << b);
		if (cur ^ last)
			x += 1 << b, last = 1;
		else
			last = 0;
	}
	cout << x << endl;
	return 0;
}
