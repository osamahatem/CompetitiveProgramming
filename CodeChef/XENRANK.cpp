/*
 * XENRANK.cpp
 *
 *  Created on: Jun 2, 2017
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

	int T;
	scanf("%d", &T);
	while (T--) {
		long long x, y;
		scanf("%lld %lld", &x, &y);
		y += x;
		long long ans = y * (y + 1) / 2;
		ans += x + 1;
		printf("%lld\n", ans);
	}
	return 0;
}
