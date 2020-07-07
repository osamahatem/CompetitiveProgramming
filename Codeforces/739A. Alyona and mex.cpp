/*
 * 739A. Alyona and mex.cpp
 *
 *  Created on: Nov 23, 2016
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

	int n, m, l, r, len = 1e6;
	scanf("%d%d", &n, &m);
	while (m--) {
		scanf("%d%d", &l, &r);
		len = min(len, r - l + 1);
	}
	printf("%d\n", len);
	for (int i = 0; i < n; i++) {
		if (i)
			printf(" ");
		printf("%d", i % len);
	}
	printf("\n");
	return 0;
}
