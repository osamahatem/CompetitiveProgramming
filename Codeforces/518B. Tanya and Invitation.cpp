/*
 * 518B. Tanya and Invitation.cpp
 *
 *  Created on: Feb 24, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int cnt1[55], cnt2[55];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	string s, t;
	int a = 0, b = 0;
	cin >> s >> t;
	for (int i = 0; i < (int) s.size(); i++) {
		int c = (isupper(s[i]) ? 26 + s[i] - 'A' : s[i] - 'a');
		cnt1[c]++;
	}
	for (int i = 0; i < (int) t.size(); i++) {
		int c = (isupper(t[i]) ? 26 + t[i] - 'A' : t[i] - 'a');
		if (cnt1[c])
			cnt1[c]--, a++;
		else
			cnt2[(c < 26 ? c + 26 : c - 26)]++;
	}
	for (int i = 0; i < 52; i++)
		b += min(cnt1[i], cnt2[i]);
	cout << a << " " << b << endl;
	return 0;
}
