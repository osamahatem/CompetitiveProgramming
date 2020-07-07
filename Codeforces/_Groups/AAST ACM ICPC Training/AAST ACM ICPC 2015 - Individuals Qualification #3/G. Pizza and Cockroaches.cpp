/*
 * G. Pizza and Cockroaches.cpp
 *
 *  Created on: Sep 10, 2015
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

	freopen("pizza.in", "r", stdin);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		int k;
		cin >> k;
		long long ans = (long long) k * (k + 1) / 2 + 1;
		cout << "Case " << t << ": " << ans << endl;
	}
	return 0;
}
