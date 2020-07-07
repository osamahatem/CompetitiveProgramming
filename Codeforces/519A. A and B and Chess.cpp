/*
 * 519A. A and B and Chess.cpp
 *
 *  Created on: Feb 28, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

map<char, int> val;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	val['Q'] = 9, val['q'] = -9;
	val['R'] = 5, val['r'] = -5;
	val['B'] = val['N'] = 3, val['b'] = val['n'] = -3;
	val['P'] = 1, val['p'] = -1;
	string in;
	int ans = 0;
	for (int i = 0; i < 8; i++) {
		cin >> in;
		for (int j = 0; j < 8; j++)
			ans += val[in[j]];
	}
	cout << (!ans ? "Draw" : (ans > 0 ? "White" : "Black")) << endl;
	return 0;
}
