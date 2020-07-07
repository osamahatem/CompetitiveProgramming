/*
 * 12289 - One-Two-Three.cpp
 *
 *  Created on: Aug 27, 2014
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

	string s, all[3] = { "one", "two", "three" };
	int n;
	cin >> n;
	while (n--) {
		cin >> s;
		for (int i = 0; i < 3; i++) {
			if (s.size() != all[i].size())
				continue;
			int d = 0;
			for (int j = 0; j < (int) s.size(); j++)
				d += (bool) (all[i][j] != s[j]);
			if (d <= 1) {
				cout << i + 1 << "\n";
				break;
			}
		}
	}
	return 0;
}
