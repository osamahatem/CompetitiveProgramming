/*
 * 467B. Fedor and New Game.cpp
 *
 *  Created on: Nov 29, 2014
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int popCount(int x) {
	int ret = 0;
	while (x) {
		ret += x & 1;
		x >>= 1;
	}
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, m, k, all[1005], my, ans = 0;
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++)
		cin >> all[i];
	cin >> my;
	for (int i = 0; i < m; i++)
		ans += (bool) (popCount(all[i] ^ my) <= k);
	cout << ans << endl;
	return 0;
}
