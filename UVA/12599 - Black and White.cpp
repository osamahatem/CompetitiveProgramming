/*
 * 12599 - Black and White.cpp
 *
 *  Created on: Aug 19, 2014
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

	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		vector<int> B, W;
		for (int i = 0; i < (int) s.size(); i++) {
			if (s[i] == 'B')
				B.push_back(i + 1);
			else
				W.push_back(i + 1);
		}
		if (W.size() == 0 || B.size() == 0)
			cout << "IMPOSSIBLE\n";
		else if (W[0] < B[0] || B.back() > W.back())
			cout << "IMPOSSIBLE\n";
		else if (B.back() < W[0]) {
			cout << "1\n" << s.size();
			for (int i = 1; i <= (int) s.size(); i++)
				cout << " " << i;
			cout << "\n";
		} else {
			cout << "2\n" << B.size();
			for (int i = 1; i < (int) B.size(); i++)
				cout << " " << B[i];
			cout << " " << W.back() << "\n" << W.size() << " " << B[0];
			for (int i = 0; i + 1 < (int) W.size(); i++)
				cout << " " << W[i];
			cout << "\n";
		}
	}
	return 0;
}
