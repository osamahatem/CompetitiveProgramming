/*
 * J. Jubilee Decoration.cpp
 *
 *  Created on: Mar 10, 2018
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

	freopen("jubilee.in", "r", stdin);
	freopen("jubilee.out", "w", stdout);

	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int n;
	while (cin >> n, n) {
		if (n < 4) {
			cout << "1\n";
			for (int i = 0; i < n; i++)
				cout << "1" << " \n"[i == n - 1];
			for (int i = 0; i < n; i++)
				cout << "1" << " \n"[i == n - 1];
		} else if (n < 7) {
			cout << "2\n";
			for (int i = 0; i < n; i++)
				cout << "12"[i & 1] << " \n"[i == n - 1];
			for (int i = 0; i < n; i++)
				cout << "12"[i & 1] << " \n"[i == n - 1];
		} else {
			cout << "3\n";
			for (int i = 0; i < n; i++)
				cout << "12"[i & 1] << " \n"[i == n - 1];
			for (int i = 0; i < n; i++)
				cout << "3" << " \n"[i == n - 1];
		}
	}
	return 0;
}
