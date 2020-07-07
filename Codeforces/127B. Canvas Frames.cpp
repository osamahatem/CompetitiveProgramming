/*
 * 127B. Canvas Frames.cpp
 *
 *  Created on: Aug 5, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int cnt[105];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, x;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		cnt[x]++;
	}
	int ans = 0;
	for (int i = 1; i <= 100; i++)
		ans += cnt[i] / 2;
	cout << ans / 2 << endl;
	return 0;
}
