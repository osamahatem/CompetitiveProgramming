/*
 * 545B. Equidistant String.cpp
 *
 *  Created on: May 19, 2015
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

	string s, t, ans;
	cin >> s >> t;
	int len = (int) s.size();
	bool flag = 0;
	for (int i = 0; i < len; i++)
		if (s[i] != t[i]) {
			if (flag)
				ans += t[i];
			else
				ans += s[i];
			flag = !flag;
		} else
			ans += s[i];
	cout << (flag ? "impossible" : ans) << endl;
	return 0;
}
