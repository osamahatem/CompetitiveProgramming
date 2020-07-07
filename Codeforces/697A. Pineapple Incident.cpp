/*
 * 697A. Pineapple Incident.cpp
 *
 *  Created on: Jul 14, 2016
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

	int t, s, x;
	cin >> t >> s >> x;
	cout << (x < t || (x > t && x < t + s) || (x - t) % s > 1 ? "NO" : "YES")
			<< endl;
	return 0;
}
