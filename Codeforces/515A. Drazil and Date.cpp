/*
 * 515A. Drazil and Date.cpp
 *
 *  Created on: Feb 17, 2015
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

	int a, b, s;
	cin >> a >> b >> s;
	int d = abs(a) + abs(b);
	d = s - d;
	cout << ((d % 2 || d < 0) ? "No" : "Yes") << endl;
	return 0;
}
