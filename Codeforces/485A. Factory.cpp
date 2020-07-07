/*
 * 485A. Factory.cpp
 *
 *  Created on: Nov 5, 2014
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

bool vis[100005];

int main() {
#ifndef ONLINE_JUDGE
//	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int a, m;
	cin >> a >> m;
	a %= m;
	while (!vis[a]) {
		vis[a] = 1;
		if (a == 0) {
			cout << "Yes\n";
			return 0;
		}
		a += a % m;
		a %= m;
	}
	cout << "No\n";
	return 0;
	return 0;
}
