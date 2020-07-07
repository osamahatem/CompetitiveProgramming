/*
 * 12640 - Largest Sum Game.cpp
 *
 *  Created on: Aug 11, 2014
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

	int x;
	string s;
	stringstream ss;
	while (getline(cin, s)) {
		int maxi = 0, maxiHere = 0;
		ss.clear();
		ss << s;
		while (ss >> x) {
			maxiHere = max(0, maxiHere + x);
			maxi = max(maxi, maxiHere);
		}
		cout << maxi << endl;
	}
	return 0;
}
