/*
 * 567C. Geometric Progression.cpp
 *
 *  Created on: Aug 6, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

map<int, long long> cnt[2];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, k, x;
	cin >> n >> k;
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> x;
		if (k == 1) {
			int t = cnt[0][x];
			ans += (long long) t * (t - 1) / 2;
		} else if (x % k == 0) {
			ans += cnt[1][x / k];
			cnt[1][x] += cnt[0][x / k];
		}
		cnt[0][x]++;
	}
	cout << ans << endl;
	return 0;
}
