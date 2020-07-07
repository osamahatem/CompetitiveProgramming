/*
 * 617A. Elephant.cpp
 *
 *  Created on: Feb 19, 2016
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

	int x, ans;
	cin >> x;
	ans = x / 5 + (x % 5 ? 1 : 0);
	cout << ans << endl;
	return 0;
}
