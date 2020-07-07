/*
 * 567B. Berland National Library.cpp
 *
 *  Created on: Aug 6, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

bool vis[1000005];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, r;
	char t;
	cin >> n;
	vector<int> all;
	for (int i = 0; i < n; i++) {
		cin >> t >> r;
		if (t == '-') {
			if (!vis[r])
				all.insert(all.begin(), r), vis[r] = 1;
			r *= -1;
		} else
			vis[r] = 1;
		all.push_back(r);
	}
	int cur = 0, ans = 0;
	for (int i = 0; i < (int) all.size(); i++) {
		int x = all[i] / abs(all[i]);
		cur += x;
		ans = max(cur, ans);
	}
	cout << ans << endl;
	return 0;
}
