/*
 * 697B. Barnicle.cpp
 *
 *  Created on: Jul 14, 2016
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

	string s;
	cin >> s;
	int ex = 0, p = 1, last = -1;
	for (int i = (int) s.size() - 1; s[i] != 'e'; i--) {
		ex += p * (s[i] - '0');
		p *= 10;
		last = i;
	}
	s = s.substr(0, last - 1);
	for (int i = 0; i < ex; i++) {
		if (i + 2 == (int) s.size())
			s += "0";
		swap(s[i + 1], s[i + 2]);
	}
	if (s.back() == '.')
		s.pop_back();
	else if (ex == 0 && s.back() == '0') {
		s.pop_back();
		s.pop_back();
	}
	cout << s << endl;
	return 0;
}
