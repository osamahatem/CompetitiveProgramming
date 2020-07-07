/*
 * 469A. I Wanna Be the Guy.cpp
 *
 *  Created on: Jun 11, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

bool vis[101];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, c, x;
	cin >> n >> c;
	int ans = n;
	while (c--) {
		cin >> x;
		ans -= !vis[x];
		vis[x] = 1;
	}
	cin >> c;
	while (c--) {
		cin >> x;
		ans -= !vis[x];
		vis[x] = 1;
	}
	cout << (ans ? "Oh, my keyboard!" : "I become the guy.") << endl;
	return 0;
}
