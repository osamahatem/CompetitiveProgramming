/*
 * 513A. Game.cpp
 *
 *  Created on: Feb 7, 2015
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

	int a, b, k1, k2;
	cin >> a >> b >> k1 >> k2;
	cout << (a > b ? "First" : "Second") << endl;
	return 0;
}
