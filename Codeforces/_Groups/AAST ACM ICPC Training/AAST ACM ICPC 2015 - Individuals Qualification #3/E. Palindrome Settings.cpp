/*
 * E. Palindrome Settings.cpp
 *
 *  Created on: Sep 10, 2015
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

	freopen("palindrome.in", "r", stdin);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		int n, m;
		string s;
		cin >> n >> m >> s;
		bool ans = 1;
		for (int i = 0; i < (n / m) / 2; i++) {
			int s1 = i * m, s2 = ((n / m) - i - 1) * m;
			if (s.substr(s1, m) != s.substr(s2, m)) {
				ans = 0;
				break;
			}
		}
		cout << "Case " << t << ": " << (ans ? "Yes" : "No") << endl;
	}
	return 0;
}
