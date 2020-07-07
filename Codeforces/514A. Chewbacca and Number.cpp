/*
 * 514A. Chewbacca and Number.cpp
 *
 *  Created on: Jun 9, 2015
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

	string x;
	cin >> x;
	for (int i = 0; i < (int) x.size(); i++) {
		char t = '9' - x[i] + '0';
		if (t < x[i] && (i || x[i] != '9'))
			x[i] = t;
	}
	cout << x << endl;
	return 0;
}
