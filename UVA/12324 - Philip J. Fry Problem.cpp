/*
 * 12324 - Philip J. Fry Problem.cpp
 *
 *  Created on: Aug 25, 2014
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

	int n, t[105], c[105];
	bool vis[105];
	while (cin >> n, n) {
		for (int i = 0; i < n; i++)
			cin >> t[i] >> c[i], vis[i] = 0;
		for (int i = n - 1; i >= 0; i--) {
			while (c[i]) {
				int maxi = 0, maxiID = 0;
				for (int j = i + 1; j < n; j++) {
					if (!vis[j] && t[j] > maxi)
						maxi = t[j], maxiID = j;
				}
				if (maxi == 0)
					break;
				vis[maxiID] = 1;
				c[i]--;
			}
		}
		int ans = 0;
		for (int i = 0; i < n; i++) {
			if (vis[i])
				ans += t[i] / 2;
			else
				ans += t[i];
		}
		cout << ans << "\n";
	}
	return 0;
}
