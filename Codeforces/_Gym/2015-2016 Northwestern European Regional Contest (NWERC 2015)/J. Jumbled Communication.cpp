/*
 * J. Jumbled Communication.cpp
 *
 *  Created on: Nov 23, 2017
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
	scanf("%d", &n);
	while (n--) {
		int x;
		scanf("%d", &x);
		int ans = 0;
		for (; ans < 256; ans++)
			if ((ans ^ ((ans << 1) & 255)) == x)
				break;
		printf("%d%c", ans, " \n"[n == 0]);
	}
	return 0;
}
