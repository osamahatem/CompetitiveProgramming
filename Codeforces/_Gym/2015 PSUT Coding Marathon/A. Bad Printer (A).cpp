/*
 * A. Bad Printer (A).cpp
 *
 *  Created on: Sep 3, 2015
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

	string in;
	cin >> in;
	cout << (count(in.begin(), in.end(), '?') ? "No" : "Yes") << endl;
	return 0;
}
