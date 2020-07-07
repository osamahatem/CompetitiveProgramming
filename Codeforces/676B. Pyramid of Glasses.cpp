/*
 * 676B. Pyramid of Glasses.cpp
 *
 *  Created on: May 25, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int cup[11][11];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, t, ans = 0;
	cin >> n >> t;
	int full = 1 << (n - 1);
	int total = t * full;
	cup[0][0] = total;
	for (int i = 0; i < n; i++)
		for (int j = 0; j <= i; j++) {
			int extra = max(0, cup[i][j] - full);
			cup[i][j] = min(cup[i][j], full);
			if (cup[i][j] == full)
				ans++;
			cup[i + 1][j] += extra / 2;
			cup[i + 1][j + 1] += extra / 2;
		}
	cout << ans << endl;
	return 0;
}
