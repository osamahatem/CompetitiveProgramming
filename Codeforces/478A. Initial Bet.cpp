/*
 * 478A. Initial Bet.cpp
 *
 *  Created on: Oct 16, 2014
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
//	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int a, sum = 0;
	for (int i = 0; i < 5; i++) {
		cin >> a;
		sum += a;
	}
	cout << ((sum % 5 || sum == 0) ? -1 : sum / 5) << endl;
	return 0;
}
