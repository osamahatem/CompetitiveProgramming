/*
 * 546A. Soldier and Bananas.cpp
 *
 *  Created on: May 22, 2015
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

	int k, n, w;
	cin >> k >> n >> w;
	int tot = k * w * (w + 1) / 2;
	tot = max(0, tot - n);
	cout << tot << endl;
	return 0;
}
