/*
 * 765A. Neverending competitions.cpp
 *
 *  Created on: Feb 14, 2017
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
	cin >> n;
	cout << (n % 2 ? "contest" : "home") << endl;
	return 0;
}
