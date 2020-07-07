/*
 * 465A. inc ARG.cpp
 *
 *  Created on: Jul 13, 2016
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

	int n, ans = 0;
	string s;
	cin >> n >> s;
	for (int i = 0; s[i] == '1'; i++)
		ans++;
	if (ans < n)
		ans++;
	cout << ans << endl;
	return 0;
}
