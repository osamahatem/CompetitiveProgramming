/*
 * 265B. Roadside Trees (Simplified Edition).cpp
 *
 *  Created on: Jun 25, 2015
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

	int n, curh = 0, h;
	cin >> n >> h;
	long long ans = h + 1;
	curh = h;
	n--;
	while (n--) {
		cin >> h;
		ans += abs(curh - h) + 2;
		curh = h;
	}
	cout << ans << endl;
	return 0;
}
