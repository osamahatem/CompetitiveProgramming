/*
 * 1991. The battle near the swamp.cpp
 *
 *  Created on: Aug 4, 2014
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

	int n, k, x = 0, y = 0, t;
	scanf("%d%d", &n, &k);
	while (n--) {
		scanf("%d", &t);
		if (t > k)
			x += t - k;
		else
			y += k - t;
	}
	printf("%d %d\n", x, y);
	return 0;
}
