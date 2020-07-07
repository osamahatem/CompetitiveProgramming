/*
 * 12293 - Box Game.cpp
 *
 *  Created on: Aug 27, 2014
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

	int n;
	while (cin >> n, n)
		cout << ((n & (n + 1)) ? "Alice\n" : "Bob\n");
	return 0;
}
