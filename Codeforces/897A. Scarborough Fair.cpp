/*
 * 897A. Scarborough Fair.cpp
 *
 *  Created on: Dec 2, 2017
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
	int n, m;
	cin >> n >> m >> s;
	while (m--) {
		int l, r;
		char c1, c2;
		cin >> l >> r >> c1 >> c2;
		l--, r--;
		for (int i = l; i <= r; i++)
			if (s[i] == c1)
				s[i] = c2;
	}
	cout << s << endl;
	return 0;
}
