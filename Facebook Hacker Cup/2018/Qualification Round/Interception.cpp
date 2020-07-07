/*
 * Interception.cpp
 *
 *  Created on: Jul 7, 2018
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif

	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		int n, x, last = -1;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> x;
			if (x == -(i + 1))
				last = i;
		}
		cin >> x;
		cout << "Case #" << t << ": ";
		if ((n - last) & 1)
			cout << "0" << endl;
		else
			cout << "1\n0.0" << endl;
	}
	return 0;
}
