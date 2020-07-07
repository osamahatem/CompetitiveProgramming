/*
 * B. Tidy Numbers.cpp
 *
 *  Created on: Apr 8, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int d[20];
long long cur = 0;

bool solve(int idx, int last, bool sm) {
	if (idx == 20)
		return true;
	for (int i = sm ? 9 : d[idx]; i >= last; i--) {
		cur = cur * 10 + i;
		if (solve(idx + 1, i, sm || (i < d[idx])))
			return true;
		cur /= 10;
	}
	return false;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif

	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		long long n;
		scanf("%lld", &n);
		for (int i = 0; i < 20; i++) {
			d[20 - i - 1] = n % 10;
			n /= 10;
		}
		cur = 0;
		solve(0, 0, 0);
		printf("Case #%d: %lld\n", t, cur);
	}
	return 0;
}
