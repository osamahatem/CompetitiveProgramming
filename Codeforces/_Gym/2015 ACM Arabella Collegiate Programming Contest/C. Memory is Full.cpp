/*
 * C. Memory is Full.cpp
 *
 *  Created on: Aug 29, 2015
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

	int t;
	cin >> t;
	while (t--) {
		int k, m, n, sz[105], emp = 0;
		cin >> k >> m >> n;
		for (int i = 0; i < n; i++) {
			cin >> sz[i];
			emp += sz[i];
		}
		emp = k - emp;
		sort(sz, sz + n, greater<int>());
		int ans = 0;
		for (int i = 0; i < n && emp < m; i++)
			emp += sz[i], ans++;
		cout << ans << endl;
	}
	return 0;
}
