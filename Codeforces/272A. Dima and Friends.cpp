/*
 * 272A. Dima and Friends.cpp
 *
 *  Created on: Aug 15, 2015
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

	int n, x, s = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		s += x;
	}
	n++, s--;
	int ans = 0;
	for (int i = 1; i <= 5; i++)
		if ((s + i) % n)
			ans++;
	cout << ans << endl;
	return 0;
}
