/*
 * 10018 - Reverse and Add.cpp
 *
 *  Created on: Aug 26, 2014
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

long long rev(long long x) {
	long long ret = 0;
	while (x) {
		ret = ret * 10 + x % 10;
		x /= 10;
	}
	return ret;
}

bool isPal(long long x) {
	return x == rev(x);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n;
	long long x;
	cin >> n;
	while (n--) {
		int c = 0;
		cin >> x;
		while (!isPal(x)) {
			x += rev(x);
			c++;
		}
		cout << c << " " << x << "\n";
	}
	return 0;
}
