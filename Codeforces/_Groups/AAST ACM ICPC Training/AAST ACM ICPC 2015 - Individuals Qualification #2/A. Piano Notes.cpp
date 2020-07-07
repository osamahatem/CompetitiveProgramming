/*
 * A. Piano Notes.cpp
 *
 *  Created on: Sep 7, 2015
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

	freopen("piano.in", "r", stdin);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		string s;
		cin >> s;
		cout << "Case " << t << ":" << endl;
		for (char i = 'a'; i <= 'g'; i++)
			cout << i << " " << count(s.begin(), s.end(), i) << endl;
	}
	return 0;
}
