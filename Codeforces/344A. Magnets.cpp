/*
 * 344A. Magnets.cpp
 *
 *  Created on: Feb 5, 2015
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

	int n, ans = 1;
	string cur, last;
	cin >> n >> last;
	for (int i = 1; i < n; i++) {
		cin >> cur;
		if (cur != last)
			ans++;
		last = cur;
	}
	cout << ans << endl;
	return 0;
}
