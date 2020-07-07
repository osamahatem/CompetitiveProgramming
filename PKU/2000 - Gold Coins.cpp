/*
 * 2000 - Gold Coins.cpp
 *
 *  Created on: Jun 17, 2017
 *      Author: Osama Hatem
 */

//#include <bits/stdtr1c++.h>
//#include <ext/numeric>
#include <cstdio>

using namespace std;

int n, ans[10005];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int a = 0, b = 1;
	for (int i = 1; i <= 10000; i++) {
		ans[i] = b + ans[i - 1];
		a++;
		if (a == b)
			b++, a = 0;
	}
	while (scanf("%d", &n), n)
		printf("%d %d\n", n, ans[n]);
	return 0;
}
