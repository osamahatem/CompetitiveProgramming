/*
 ID: 19semse1
 PROG: skidesign
 LANG: C++
 */
/*
 * skidesign.cpp
 *
 *  Created on: Feb 26, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("skidesign.in", "r", stdin);
	freopen("skidesign.out", "w", stdout);
#endif

	int n, h[1005], ans = 1 << 30;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> h[i];
	for (int i = 17; i <= 100; i++) {
		int temp = 0;
		for (int j = 0; j < n; j++) {
			int cost = min(abs(h[j] - i), abs(h[j] - i + 17));
			if (h[j] <= i && h[j] >= i - 17)
				cost = 0;
			cost *= cost;
			temp += cost;
		}
		ans = min(ans, temp);
	}
	cout << ans << endl;
	return 0;
}
