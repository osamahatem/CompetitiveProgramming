/*
 * 65A. Harry Potter and Three Spells.cpp
 *
 *  Created on: Aug 8, 2015
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

	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;
	if ((!c && d) || (!a && b && d) || (!e && f && b && d)) {
		cout << "Ron" << endl;
		return 0;
	}
	if (!b || !d || !f) {
		cout << "Hermione" << endl;
		return 0;
	}
	double ratio = (double) b / a * d / c * f / e;
	cout << (ratio > 1.0 ? "Ron" : "Hermione") << endl;
	return 0;
}
