/*
 * 463B. Caisa and Pylons.cpp
 *
 *  Created on: Jul 11, 2016
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

	int n, x, ans = 0;
	scanf("%d", &n);
	while (n--) {
		scanf("%d", &x);
		ans = max(ans, x);
	}
	printf("%d\n", ans);
	return 0;
}
