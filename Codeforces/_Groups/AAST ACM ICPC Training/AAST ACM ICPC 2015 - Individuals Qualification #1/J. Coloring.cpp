/*
 * J. Coloring.cpp
 *
 *  Created on: Sep 6, 2015
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

	freopen("coloring.in", "r", stdin);
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		string s;
		int k, cnt = 0;
		cin >> s >> k;
		int sz = (int) s.size();
		for (int i = 0; i < sz / 2; i++)
			if (s[i] != s[sz - 1 - i])
				cnt++;
		cout << "Case " << i << ": " << (cnt <= k ? "YES" : "NO") << endl;
	}
	return 0;
}
