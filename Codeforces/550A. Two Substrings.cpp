/*
 * 550A. Two Substrings.cpp
 *
 *  Created on: Jun 4, 2015
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
	int fa = -1, la = -1, fb = -1, lb = -1;
	cin >> s;
	for (int i = 0; i + 1 < (int) s.size(); i++) {
		if (s[i] == 'A' && s[i + 1] == 'B' && fa == -1)
			fa = i;
		if (s[i] == 'B' && s[i + 1] == 'A' && fb == -1)
			fb = i;
	}
	for (int i = (int) s.size() - 1; i > 0; i--) {
		if (s[i - 1] == 'A' && s[i] == 'B' && la == -1)
			la = i - 1;
		if (s[i - 1] == 'B' && s[i] == 'A' && lb == -1)
			lb = i - 1;
	}
	if (fa == -1 || la == -1 || fb == -1 || lb == -1) {
		cout << "NO" << endl;
		return 0;
	}
	if (fa + 1 < lb || fb + 1 < la)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}
