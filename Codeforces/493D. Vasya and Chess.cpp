/*
 * 493D. Vasya and Chess.cpp
 *
 *  Created on: Dec 3, 2014
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
	if (n % 2)
		cout << "black\n";
	else
		cout << "white\n1 2\n";
	return 0;
}
