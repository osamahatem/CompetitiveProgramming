/*
 * 276A. Lunch Rush.cpp
 *
 *  Created on: Jun 20, 2016
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

	int n, k, ans = -(1 << 30);
	scanf("%d%d", &n, &k);
	while (n--) {
		int f, t;
		scanf("%d%d", &f, &t);
		if (t > k)
			f -= t - k;
		ans = max(ans, f);
	}
	printf("%d\n", ans);
	return 0;
}
