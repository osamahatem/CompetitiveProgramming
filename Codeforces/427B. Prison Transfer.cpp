/*
 * 427B. Prison Transfer.cpp
 *
 *  Created on: Jun 29, 2015
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

	int n, t, c, x, ans = 0, last = -1;
	cin >> n >> t >> c;
	for (int i = 0; i < n; i++) {
		cin >> x;
		if (x > t)
			last = i;
		else if (i - last >= c)
			ans++;
	}
	cout << ans << endl;
	return 0;
}
