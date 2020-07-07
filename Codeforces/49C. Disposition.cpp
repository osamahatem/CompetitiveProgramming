/*
 * 49C. Disposition.cpp
 *
 *  Created on: Aug 9, 2015
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
	if (n % 2)
		cout << "1";
	for (int i = n % 2; i + 1 < n; i += 2) {
		if (i)
			cout << " ";
		cout << i + 2 << " " << i + 1;
	}
	cout << endl;
	return 0;
}
