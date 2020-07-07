/*
 * 401C. Team.cpp
 *
 *  Created on: Jul 18, 2015
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

	int zeros, ones;
	cin >> zeros >> ones;
	string ans = "";
	while (zeros && ones && ones > zeros)
		ans += "110", ones -= 2, zeros--;
	while (zeros && ones)
		ans += "10", zeros--, ones--;
	if (ones < 3)
		while (ones)
			ans += "1", ones--;
	if (zeros)
		ans = "0" + ans, zeros--;
	if (ones || zeros)
		cout << "-1" << endl;
	else
		cout << ans << endl;
	return 0;
}
