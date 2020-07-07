/*
 * K. Arithmetic Progression.cpp
 *
 *  Created on: Sep 7, 2015
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

	freopen("arith.in", "r", stdin);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		int a, b;
		cin >> a >> b;
		cout << b + b - a << endl;
	}
	return 0;
}
