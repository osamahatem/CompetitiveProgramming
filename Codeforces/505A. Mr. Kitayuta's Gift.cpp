/*
 * 505A. Mr. Kitayuta's Gift.cpp
 *
 *  Created on: Jan 18, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

bool isPal(string s) {
	string rs = s;
	reverse(rs.begin(), rs.end());
	return s == rs;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	string in;
	cin >> in;
	int sz = (int) in.size();
	for (int i = 0; i <= sz; i++) {
		for (int c = 0; c < 26; c++) {
			string t = in.substr(0, i);
			t += (char) ('a' + c);
			t += in.substr(i, sz - i);
			if (isPal(t)) {
				cout << t << endl;
				return 0;
			}
		}
	}
	cout << "NA" << endl;
	return 0;
}
