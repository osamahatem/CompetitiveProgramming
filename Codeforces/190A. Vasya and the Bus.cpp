/*
 * 190A. Vasya and the Bus.cpp
 *
 *  Created on: Apr 16, 2015
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

	int n, m;
	cin >> n >> m;
	if (!n && m) {
		cout << "Impossible" << endl;
		return 0;
	}
	cout << n + max(0, m - n) << " " << n + max(0, m - 1) << endl;
	return 0;
}
