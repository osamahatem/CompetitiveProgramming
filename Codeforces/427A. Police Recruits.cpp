/*
 * 427A. Police Recruits.cpp
 *
 *  Created on: Jun 29, 2015
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

	int n, ans = 0, cur = 0, x;
	cin >> n;
	while (n--) {
		cin >> x;
		cur += x;
		if (cur < 0)
			ans++, cur = 0;
	}
	cout << ans << endl;
	return 0;
}
