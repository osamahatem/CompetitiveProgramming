/*
 * 235A. LCM Challenge.cpp
 *
 *  Created on: Aug 11, 2015
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
	if (n < 3) {
		cout << n << endl;
		return 0;
	}
	long long ans;
	if (n % 2)
		ans = (long long) n * (n - 1) * (n - 2);
	else if (n % 3)
		ans = (long long) n * (n - 1) * (n - 3);
	else
		ans = (long long) (n - 1) * (n - 2) * (n - 3);
	cout << ans << endl;
	return 0;
}
