/*
 * 624A. Save Luke.cpp
 *
 *  Created on: Mar 22, 2016
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

	int d, l, v1, v2;
	cin >> d >> l >> v1 >> v2;
	double t = (double) (l - d) / (v1 + v2);
	cout << fixed << setprecision(6) << t << endl;
	return 0;
}
