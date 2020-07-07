/*
 * F. Another Square in the Floor.cpp
 *
 *  Created on: Sep 29, 2015
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

	freopen("square.in", "r", stdin);
	int T, x, y;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &x, &y);
		x = max(x, y);
		printf("%d\n", x * x);
	}
	return 0;
}
