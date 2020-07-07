/*
 * 604A. Uncowed Forces.cpp
 *
 *  Created on: Feb 26, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int ac[5], w[5];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	double ans = 0.0;
	for (int i = 0; i < 5; i++)
		cin >> ac[i];
	for (int i = 0; i < 5; i++) {
		cin >> w[i];
		int x = 500 * (i + 1);
		ans += max(0.3 * x, (1.0 - ac[i] / 250.0) * x - 50 * w[i]);
	}
	cin >> ac[0] >> ac[1];
	ans += 100.0 * ac[0] - 50.0 * ac[1];
	cout << fixed << setprecision(0) << ans << endl;
	return 0;
}
