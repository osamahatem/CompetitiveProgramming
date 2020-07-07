/*
 * 460A. Vasya and Socks.cpp
 *
 *  Created on: Aug 20, 2014
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

	int n, m, d = 0;
	cin >> n >> m;
	for (int i = 1; n; i++) {
		n--;
		if (i % m == 0)
			n++;
		d++;
	}
	cout << d << "\n";
	return 0;
}
