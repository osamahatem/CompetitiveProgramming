/*
 * 510A. Fox And Snake.cpp
 *
 *  Created on: Feb 3, 2015
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

	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (i % 2 || (j == m && (i / 2) % 2)
					|| (j == 1 && (i / 2) % 2 == 0))
				cout << "#";
			else
				cout << ".";
		}
		cout << endl;
	}
	return 0;
}
