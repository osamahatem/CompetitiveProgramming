/*
 * K. Tournament Wins.cpp
 *
 *  Created on: Oct 11, 2017
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

	int k, r;
	cin >> k >> r;
	int n = 1 << k;
	int lower = n - r;
	double ans = 0.0, last = 0.0;
	for (int i = k; i; i--) {
		int need = (1 << i) - 1;
		double cur = 1.0;
		for (int j = 1; j <= need; j++)
			cur *= 1.0 * (lower - j + 1) / (n - j);
		ans += i * (cur - last);
		last = cur;
	}
	cout << fixed << setprecision(5) << ans << endl;
	return 0;
}
