/*
 * 589I. Lottery.cpp
 *
 *  Created on: Oct 20, 2015
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

	int n, k, x, ans = 0;
	cin >> n >> k;
	map<int, int> cnt;
	for (int i = 0; i < n; i++) {
		cin >> x;
		cnt[x]++;
		if (cnt[x] > n / k)
			ans++;
	}
	cout << ans << endl;
	return 0;
}
