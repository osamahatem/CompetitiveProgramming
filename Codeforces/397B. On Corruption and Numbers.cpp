/*
 * 397B. On Corruption and Numbers.cpp
 *
 *  Created on: Aug 15, 2015
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

	int t;
	cin >> t;
	while (t--) {
		int n, l, r;
		cin >> n >> l >> r;
		cout << ((long long) n / l * r >= n ? "Yes" : "No") << endl;
	}
	return 0;
}
