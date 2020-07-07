/*
 * 765B. Code obfuscation.cpp
 *
 *  Created on: Feb 14, 2017
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
	char cur = 'a';
	for (int i = 0; s[i]; i++) {
		if (s[i] == cur)
			cur++;
		if (s[i] > cur) {
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	return 0;
}
