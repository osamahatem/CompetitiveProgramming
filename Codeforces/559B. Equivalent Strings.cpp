/*
 * 559B. Equivalent Strings.cpp
 *
 *  Created on: Jul 22, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

string sSort(string S) {
	if (S.size() % 2)
		return S;
	int m = S.size() / 2;
	string s1 = sSort(S.substr(0, m)), s2 = sSort(S.substr(m, m));
	return (s1 < s2 ? s1 + s2 : s2 + s1);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	string a, b;
	cin >> a >> b;
	cout << (sSort(a) == sSort(b) ? "YES" : "NO") << endl;
	return 0;
}
