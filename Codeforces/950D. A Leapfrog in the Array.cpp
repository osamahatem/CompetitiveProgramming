/*
 * 950D. A Leapfrog in the Array.cpp
 *
 *  Created on: Apr 9, 2018
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

	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	long long n, x;
	int q;
	cin >> n >> q;

	while (q--) {
		cin >> x;
		while ((x & 1) == 0)
			x += n - x / 2;
		cout << x / 2 + 1 << endl;
	}
	return 0;
}
