/*
 * 621B. Wet Shark and Bishops.cpp
 *
 *  Created on: Mar 6, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

map<int, int> cnt1, cnt2;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, x, y;
	long long ans = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &x, &y);
		ans += cnt1[x - y]++;
		ans += cnt2[1000 - x - y]++;
	}
	printf("%lld\n", ans);
	return 0;
}
