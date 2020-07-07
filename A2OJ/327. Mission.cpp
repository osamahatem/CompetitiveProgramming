/*
 * 327. Mission.cpp
 *
 *  Created on: Nov 12, 2014
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

	int t, tc = 0;
	cin >> t;
	while (t--) {
		cout << "Case " << ++tc << ": " << endl;
		int n, m, k;
		cin >> n >> m >> k;
		string team, col;
		map<string, int> cnt;
		while (n--) {
			cin >> team >> col;
			if (k == 0)
				continue;
			if (cnt[col] == m)
				continue;
			cout << team << endl;
			cnt[col]++;
			k--;
		}
	}
	return 0;
}
