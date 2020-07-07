/*
 * 11933 - Splitting Numbers.cpp
 *
 *  Created on: Sep 30, 2014
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
	while (cin >> n, n) {
		int bit = 0, a = 0, b = 0;
		bool flag = 1;
		while (n) {
			if (n & (1 << bit)) {
				if (flag)
					a += 1 << bit;
				else
					b += 1 << bit;
				n -= 1 << bit;
				flag = !flag;
			}
			bit++;
		}
		cout << a << " " << b << "\n";
	}
	return 0;
}
