/*
 * 518A. Vitaly and Strings.cpp
 *
 *  Created on: Feb 24, 2015
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

	string s, t, a, b;
	bool flag = 0;
	cin >> s >> t;
	for (int i = 0; i < (int) s.size(); i++) {
		if (flag)
			a += 'z', b += 'a';
		else if (s[i] == t[i])
			a += s[i], b += s[i];
		else {
			flag = 1;
			a += s[i], b += s[i] + 1;
		}
	}
	if (a > s && a < t)
		cout << a << endl;
	else if (b > s && b < t)
		cout << b << endl;
	else
		cout << "No such string" << endl;
	return 0;
}
