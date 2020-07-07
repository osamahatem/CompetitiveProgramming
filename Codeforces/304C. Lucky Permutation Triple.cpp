/*
 * 304C. Lucky Permutation Triple.cpp
 *
 *  Created on: Dec 5, 2014
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
	if (n % 2 == 0) {
		cout << "-1" << endl;
		return 0;
	}
	for (int i = 0; i < n; i++) {
		if (i)
			cout << " ";
		cout << i;
	}
	cout << endl;
	for (int i = 0; i < n; i++) {
		if (i)
			cout << " ";
		cout << i;
	}
	cout << endl;
	for (int i = 0; i < n; i++) {
		if (i)
			cout << " ";
		cout << 2 * i % n;
	}
	cout << endl;
	return 0;
}
