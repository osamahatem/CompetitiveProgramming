/*
 * Equalize the Array.cpp
 *
 *  Created on: Jul 12, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int cnt[105];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, x, ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		ans = max(ans, ++cnt[x]);
	}
	cout << n - ans << endl;
	return 0;
}
