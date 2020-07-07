/*
 * 12663 - High bridge, low bridge.cpp
 *
 *  Created on: Aug 31, 2014
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;
const int MAXN = 1e5 + 5;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int t = 0, n, m, k, h[MAXN], change[MAXN];
	while (cin >> n >> m >> k) {
		memset(change, 0, sizeof change);
		for (int i = 0; i < n; i++)
			cin >> h[i];
		sort(h, h + n);
		int last = 1, a, b;
		cout << "Case " << ++t << ": ";
		while (m--) {
			cin >> a >> b;
			int s = upper_bound(h, h + n, last) - h;
			int e = upper_bound(h, h + n, a) - h;
			last = b;
			change[s]++, change[e]--;
		}
		int cur = 0, ans = 0;
		for (int i = 0; i < n; i++) {
			cur += change[i];
			if (cur >= k)
				ans++;
		}
		cout << ans << "\n";
	}
	return 0;
}
