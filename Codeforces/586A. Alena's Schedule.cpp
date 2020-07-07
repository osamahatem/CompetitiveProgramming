/*
 * 586A. Alena's Schedule.cpp
 *
 *  Created on: Oct 12, 2015
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

	int n, ans = 0, a, z = 0;
	bool one = 0;
	cin >> n;
	while (n--) {
		cin >> a;
		if (!a && !one)
			continue;
		if (a) {
			one = 1;
			ans += 1 + (z == 1 ? 1 : 0);
			z = 0;
		} else
			z++;
	}
	cout << ans << endl;
	return 0;
}
