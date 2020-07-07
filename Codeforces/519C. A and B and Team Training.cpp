/*
 * 519C. A and B and Team Training.cpp
 *
 *  Created on: Feb 28, 2015
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

	int n, m, ans = 0;
	cin >> n >> m;
	while (n + m > 2 && n && m) {
		if (m > n)
			m -= 2, n--;
		else
			m--, n -= 2;
		ans++;
	}
	cout << ans << endl;
	return 0;
}
