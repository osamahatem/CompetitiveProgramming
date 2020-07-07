/*
 * 225A. Dice Tower.cpp
 *
 *  Created on: Aug 5, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

bool val[7];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, t, a, b;
	cin >> n >> t;
	t = 7 - t;
	for (int i = 0; i < n; i++) {
		for (int f = 1; f <= 6; f++)
			val[f] = 1;
		cin >> a >> b;
		val[a] = val[7 - a] = val[b] = val[7 - b] = val[t] = 0;
		int c = 0;
		for (int f = 1; f <= 6; f++)
			c += val[f] == 1;
		if (c != 1) {
			cout << "NO" << endl;
			return 0;
		}
		for (int f = 1; f <= 6; f++)
			if (val[f])
				t = 7 - f;
	}
	cout << "YES" << endl;
	return 0;
}
