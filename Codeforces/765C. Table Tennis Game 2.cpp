/*
 * 765C. Table Tennis Game 2.cpp
 *
 *  Created on: Feb 14, 2017
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

	int k, a, b;
	cin >> k >> a >> b;
	int ans = a / k + b / k;
	if (ans == 0)
		ans = -1;
	if (a % k && b / k == 0)
		ans = -1;
	if (b % k && a / k == 0)
		ans = -1;
	cout << ans << endl;
	return 0;
}
