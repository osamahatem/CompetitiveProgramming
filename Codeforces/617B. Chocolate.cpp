/*
 * 617B. Chocolate.cpp
 *
 *  Created on: Feb 19, 2016
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

	int n, x, last = -1;
	long long ans = 1;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		if (x == 1) {
			if (last != -1)
				ans *= i - last;
			last = i;
		}
	}
	if (last == -1)
		ans = 0;
	cout << ans << endl;
	return 0;
}
