/*
 * 439A. Vasya and Football.cpp
 *
 *  Created on: Dec 3, 2014
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int cards[2][100];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	string h, a;
	cin >> h >> a;
	int n;
	cin >> n;
	while (n--) {
		int m, p, tm, add;
		char t, c;
		cin >> m >> t >> p >> c;
		add = (c == 'y' ? 1 : 2);
		tm = (t == 'a' ? 0 : 1);
		cards[tm][p] += add;
		if (cards[tm][p] == 2 || (add == 2 && cards[tm][p] == 3))
			cout << (t == 'a' ? a : h) << " " << p << " " << m << endl;
	}
	return 0;
}
