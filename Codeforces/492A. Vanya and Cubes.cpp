/*
 * 492A. Vanya and Cubes.cpp
 *
 *  Created on: Dec 1, 2014
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

	int n, ans = 0, cur = 1;
	cin >> n;
	while (n >= cur) {
		ans++;
		n -= cur;
		cur += ans + 1;
	}
	cout << ans << endl;
	return 0;
}
