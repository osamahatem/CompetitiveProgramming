/*
 * 464A. No to Palindromes!.cpp
 *
 *  Created on: Aug 3, 2015
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

	int n, p;
	string s;
	cin >> n >> p >> s;
	s = "  " + s;
	bool flag = 0;
	for (int i = n + 1; i > 1; i--) {
		for (int c = s[i] + 1; c < p + 'a'; c++)
			if (c != s[i - 1] && c != s[i - 2]) {
				s[i] = c, flag = 1;
				break;
			}
		if (flag) {
			for (int j = i + 1; j < n + 2; j++) {
				bool changed = 0;
				for (int c = 'a'; c < 'a' + p; c++) {
					if (c != s[j - 1] && c != s[j - 2]) {
						s[j] = c, changed = 1;
						break;
					}
				}
				if (!changed) {
					cout << "NO" << endl;
					return 0;
				}
			}
			break;
		}
	}
	if (!flag) {
		cout << "NO" << endl;
		return 0;
	}
	cout << s.substr(2, n) << endl;
	return 0;
}
