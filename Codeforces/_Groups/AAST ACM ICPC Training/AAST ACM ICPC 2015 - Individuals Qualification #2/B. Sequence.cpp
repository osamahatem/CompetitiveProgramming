/*
 * B. Sequence.cpp
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

	freopen("sequence.in", "r", stdin);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		string a, b;
		cin >> a >> b;
		int c = 0;
		for (int i = 0; i < (int) a.size() && c < (int) b.size(); i++)
			c += a[i] == b[c];
		cout << "Case " << t << ": " << (c == (int) b.size() ? "YES" : "NO")
				<< endl;
	}
	return 0;
}
