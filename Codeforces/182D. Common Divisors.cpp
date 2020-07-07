/*
 * 182D. Common Divisors.cpp
 *
 *  Created on: Feb 27, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

string s;

bool test(string &ss, int x) {
	for (int i = 0; i < (int) ss.size(); i++)
		if (ss[i] != s[i % x])
			return false;
	return true;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	string s1, s2;
	cin >> s1 >> s2;
	int l1 = s1.size(), l2 = s2.size(), ans = 0;
	s = (l1 < l2 ? s1 : s2);
	for (int i = 1; i <= min(l1, l2); i++)
		if (l1 % i == 0 && l2 % i == 0 && test(s1, i) && test(s2, i))
			ans++;
	cout << ans << endl;
	return 0;
}
