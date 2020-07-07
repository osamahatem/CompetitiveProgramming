/*
 * B. Three Angles.cpp
 *
 *  Created on: Aug 29, 2015
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

	int t;
	cin >> t;
	while (t--) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a && b && c && a + b + c == 180)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}
