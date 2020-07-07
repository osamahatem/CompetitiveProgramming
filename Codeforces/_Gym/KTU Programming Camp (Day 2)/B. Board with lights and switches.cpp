/*
 * B. Board with lights and switches.cpp
 *
 *  Created on: May 13, 2016
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

	long long n;
	cin >> n;
	if (n < 5) {
		cout << "-1" << endl;
		return 0;
	}
	long long cnt = 0;
	int ans = 0;
	while (cnt < 1000000000) {
		ans++;
		long long a = n / 2;
		n = a * (n - a);
		cnt += n;
	}
	cout << ans << endl;
	return 0;
}
