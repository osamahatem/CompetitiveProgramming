/*
 * 11849 - CD.cpp
 *
 *  Created on: Sep 28, 2014
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

	int n, m;
	while (cin >> n >> m, n != 0 || m != 0) {
		set<int> pos;
		int x;
		for (int i = 0; i < n; i++) {
			cin >> x;
			pos.insert(x);
		}
		int ans = 0;
		for (int i = 0; i < m; i++) {
			cin >> x;
			if (pos.count(x))
				ans++;
		}
		cout << ans << "\n";
	}
	return 0;
}
