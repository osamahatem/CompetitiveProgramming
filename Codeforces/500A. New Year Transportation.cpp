/*
 * 500A. New Year Transportation.cpp
 *
 *  Created on: Dec 30, 2014
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

	int n, t, cur = 1, add[30005];
	cin >> n >> t;
	for (int i = 1; i <= n; i++)
		cin >> add[i];
	while (cur < t)
		cur += add[cur];
	cout << (cur == t ? "YES\n" : "NO\n");
	return 0;
}
