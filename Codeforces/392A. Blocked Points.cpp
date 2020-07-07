/*
 * 392A. Blocked Points.cpp
 *
 *  Created on: Aug 15, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const double EPS = 1e-9;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, last = 0;
	long long ans = 0;
	cin >> n;
	if (!n) {
		cout << "1" << endl;
		return 0;
	}
	for (int x = n; x >= -n; x--) {
		int y = (int) (sqrt((long long) n * n - (long long) x * x) + EPS);
		ans += 2 * max(abs(y - last), 1);
		last = y;
	}
	ans -= 2;
	cout << ans << endl;
	return 0;
}
