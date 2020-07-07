/*
 * B. Revenge of the Pancakes.cpp
 *
 *  Created on: Apr 9, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif

	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cout << "Case #" << t << ": ";
		string s;
		cin >> s;
		int ans = 0;
		if (s.back() == '-')
			ans++;
		int idx = 0;
		while (idx < (int) s.size()) {
			char c = s[idx];
			while (idx < (int) s.size() && s[idx] == c)
				idx++;
			ans++;
		}
		ans--;
		cout << ans << endl;
	}
	return 0;
}
