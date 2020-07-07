/*
 * A. Keys.cpp
 *
 *  Created on: Sep 10, 2015
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

	freopen("keys.in", "r", stdin);
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		int n, m, h, ans = 0;
		scanf("%d%d%d", &n, &m, &h);
		vector<pair<int, int>> all(h);
		for (int i = 0; i < h; i++)
			scanf("%d%d", &all[i].first, &all[i].second);
		sort(all.begin(), all.end());
		int last = 0, cnt = 0;
		for (int i = 0; i < h; i++) {
			if (all[i].first != last) {
				ans += cnt > 0;
				cnt = 0, last = all[i].first;
			}
			if (all[i].second > n - m)
				cnt++;
		}
		ans += cnt > 0;
		cout << "Case " << t << ": " << ans << endl;
	}
	return 0;
}
