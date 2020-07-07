/*
 * 540A. Combination Lock.cpp
 *
 *  Created on: Apr 30, 2015
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

	int n, temp, ans = 0;
	string a, b;
	cin >> n >> a >> b;
	for (int i = 0; i < n; i++) {
		temp = abs(a[i] - b[i]);
		temp = min(temp, 10 - temp);
		ans += temp;
	}
	cout << ans << endl;
	return 0;
}
