/*
 * 980A. Links and Pearls.cpp
 *
 *  Created on: May 8, 2018
 *      Author: Osama Hatem
 */

/*
 * http://codeforces.com/blog/entry/59350
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	string s;
	int a = 0, b = 0;
	cin >> s;
	for (int i = 0; s[i]; i++)
		a += s[i] == 'o', b += s[i] == '-';
	cout << (a == 0 || b % a == 0 ? "YES" : "NO") << endl;
	return 0;
}
