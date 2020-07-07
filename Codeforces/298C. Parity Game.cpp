/*
 * 298C. Parity Game.cpp
 *
 *  Created on: Jun 17, 2015
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

	string a, b;
	cin >> a >> b;
	int c1 = 0, c2 = 0;
	for (int i = 0; i < (int) a.size(); i++)
		c1 += (a[i] == '1');
	for (int i = 0; i < (int) b.size(); i++)
		c2 += (b[i] == '1');
	if (c1 & 1)
		c1++;
	cout << (c2 <= c1 ? "YES" : "NO") << endl;
	return 0;
}
