/*
 * IMPUNITS.cpp
 *
 *  Created on: Jun 17, 2017
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

	int n;
	while (scanf("%d", &n), n != -1) {
		long long a = 1, b = 1;
		for (int i = 1; i < n; i++) {
			int c, d;
			scanf("%d%d", &c, &d);
			a *= c, b *= d;
			long long g = __gcd(a, b);
			a /= g, b /= g;
		}
		printf("%lld %lld\n", a, b);
	}
	return 0;
}
