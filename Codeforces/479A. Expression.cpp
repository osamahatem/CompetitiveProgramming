/*
 * 479A. Expression.cpp
 *
 *  Created on: Jun 11, 2016
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

	int a, b, c;
	cin >> a >> b >> c;
	int ans = a * b * c;
	ans = max(ans, (a + b) * c);
	ans = max(ans, a + b * c);
	ans = max(ans, a * (b + c));
	ans = max(ans, a * b + c);
	ans = max(ans, a + b + c);
	cout << ans << endl;
	return 0;
}
