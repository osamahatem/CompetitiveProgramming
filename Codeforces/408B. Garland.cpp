/*
 * 408B. Garland.cpp
 *
 *  Created on: May 15, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int cnta[26], cntb[26];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	string a, b;
	cin >> a >> b;
	for (int i = 0; i < (int) a.size(); i++)
		cnta[a[i] - 'a']++;
	for (int i = 0; i < (int) b.size(); i++)
		cntb[b[i] - 'a']++;
	int area = 0;
	for (int i = 0; i < 26; i++) {
		if (!cnta[i] && cntb[i]) {
			cout << "-1" << endl;
			return 0;
		}
		area += min(cnta[i], cntb[i]);
	}
	cout << area << endl;
	return 0;
}
