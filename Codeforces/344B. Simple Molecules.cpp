/*
 * 344B. Simple Molecules.cpp
 *
 *  Created on: Feb 6, 2015
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

	int a, b, c;
	cin >> a >> b >> c;
	if ((a + b + c) % 2) {
		cout << "Impossible" << endl;
		return 0;
	}
	int x = (a + b - c) / 2;
	int y = (b + c - a) / 2;
	int z = (a + c - b) / 2;
	if (x < 0 || y < 0 || z < 0) {
		cout << "Impossible" << endl;
		return 0;
	}
	cout << x << " " << y << " " << z << endl;
	return 0;
}
