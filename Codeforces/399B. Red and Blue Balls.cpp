/*
 * 399B. Red and Blue Balls.cpp
 *
 *  Created on: Jun 18, 2015
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
	string s;
	cin >> n >> s;
	long long ans = 0;
	for (int i = n - 1; i >= 0; i--)
		ans = ans * 2 + (s[i] == 'B');
	cout << ans << endl;
	return 0;
}
