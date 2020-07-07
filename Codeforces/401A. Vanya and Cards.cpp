/*
 * 401A. Vanya and Cards.cpp
 *
 *  Created on: Jul 18, 2015
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

	int n, x, y, sum = 0;
	cin >> n >> x;
	while (n--) {
		cin >> y;
		sum += y;
	}
	sum = abs(sum);
	cout << (sum + x - 1) / x << endl;
	return 0;
}
