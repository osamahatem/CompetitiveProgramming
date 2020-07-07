/*
 * Ethan Searches for a String.cpp
 *
 *  Created on: Jul 7, 2018
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int fail[2005];
string p;

void computeFail() {
	fail[0] = 0;
	int len = 0;
	for (int i = 1; p[i]; i++) {
		while (len && p[len] != p[i])
			len = fail[len - 1];
		if (p[len] == p[i])
			len++;
		fail[i] = len;
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif

	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> p;
		computeFail();
		int ans = -1;
		for (int i = 1; p[i]; i++) {
			if (fail[i] <= fail[i - 1] && fail[i - 1]) {
				ans = i - 1;
				break;
			}
		}
		cout << "Case #" << t << ": ";
		if (ans == -1)
			cout << "Impossible" << endl;
		else
			cout << p.substr(0, ans) << p << endl;
	}
	return 0;
}
