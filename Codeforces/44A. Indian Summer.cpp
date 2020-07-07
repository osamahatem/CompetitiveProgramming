/*
 * 44A. Indian Summer.cpp
 *
 *  Created on: Apr 13, 2016
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
	string s1, s2;
	set<pair<string, string>> all;
	cin >> n;
	while (n--) {
		cin >> s1 >> s2;
		all.insert(make_pair(s1, s2));
	}
	cout << all.size() << endl;
	return 0;
}
