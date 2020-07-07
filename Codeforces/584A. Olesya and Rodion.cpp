/*
 * 584A. Olesya and Rodion.cpp
 *
 *  Created on: Oct 7, 2015
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

	int n, t;
	cin >> n >> t;
	if (n == 1 && t == 10) {
		cout << "-1" << endl;
		return 0;
	}
	string ans;
	for (int i = 0; i < n; i++)
		ans += (t < 10 ? '0' + t : (i < n - 1 ? '1' : '0'));
	cout << ans << endl;
	return 0;
}
