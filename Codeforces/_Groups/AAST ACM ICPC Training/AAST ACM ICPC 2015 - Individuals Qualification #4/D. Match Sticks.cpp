/*
 * D. Match Sticks.cpp
 *
 *  Created on: Sep 15, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int cnt[10];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	freopen("sticks.in", "r", stdin);
	cnt[1] = 2;
	cnt[7] = 3;
	cnt[4] = 4;
	cnt[2] = cnt[3] = cnt[5] = 5;
	cnt[0] = cnt[6] = cnt[9] = 6;
	cnt[8] = 7;
	int T;
	cin >> T;
	while (T--) {
		int n, ans = 0;
		cin >> n;
		do {
			ans += cnt[n % 10];
			n /= 10;
		} while (n);
		cout << ans << endl;
	}
	return 0;
}
